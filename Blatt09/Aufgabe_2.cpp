/*
 a) Die Konsole gibt beim Ausführen des Programms den Fehler
      Segmentation fault (core dumped)
    aus.

    Die Variable int i aus Zeile 3 wird gelöscht, sobald die aufgerufene Funktion verlassen wird.
    Dadurch entsteht nicht definiertes Verhalten, da der Zeiger auf einen Speicherplatz zeigt, der
    nicht mehr belegt ist und versucht diesen als int zu interpretieren.

    In Zeile 23 werden die dereferenzierten Werte zweier Zeiger addiert, die gelöscht wurden. Auch
    das resultiert in undefiniertem Verhalten. Für Zeile 23 wirft die Programmierumgebung nichts
    aus. Dafür wirft sie für die Zeilen 5 und 10 Warnungen aus, dass der Zeiger einer lokalen
    Variable zurückgegeben wird.

    Es ist schwer vorauszusagen, welchen Effekt die Funtkion void procrastinate(int k) auf die
    Ausgabe in Zeile 26 hat.

 b) Das char buffer[] Feld muss eine Größe von 25 haben. Wenn der Speicher zu klein angelegt wird
    wirft Konsole:
      *** stash smashing detected ***: terminted
      Aborted (core dumped)
    aus. Das bedeutet, dass char buffer[] zu kurz ist, um die beiden Vektoren zu speichern. Die
    überflüssigen Informationen werden in den auf char buffer[] folgenden Speicher geschrieben.
    Das kann zu nicht definiertem Verhalten führen.
 */
#include "fcpp.hh"

const short SIZE{ 5 };

typedef struct vector {
  float vals[SIZE];
} vector;

void vector_copy(vector* v, vector* target) {
  for(int i{ 0 }; i < SIZE; i++) {
    target->vals[i] = v->vals[i];
  }
}

float buffered_vector_product(char buffer[]) {
  // soll die das Ergebnis des skalarproducts enthalten
  float scalar_product{ 0 };

  // liest die beiden Vektoren aus char buffer[]
  vector* A{ (vector*) buffer };
  vector* B{ (vector*) (buffer + sizeof(vector)) };

  // bildet das Skalarprodukt
  for(int i{ 0 }; i < SIZE; ++i) {
    scalar_product =  scalar_product + A->vals[i] * B->vals[i];
  }

  // gibt das Ergebnis der Berechnung zurück
  return scalar_product;
}

int main() {
  char buffer[25] {};
  vector A = {{1.0f, 1.5f, 2.0f, 2.5f, 3.0f}};
  vector B = {{0.5f, -1.0f, 1.5f, -2.0f, 2.5f}};

  vector_copy(&A, (vector*) buffer);
  vector_copy(&B, (vector*) (buffer + sizeof(vector)));

  print(buffered_vector_product(buffer));

  return 0;
}
