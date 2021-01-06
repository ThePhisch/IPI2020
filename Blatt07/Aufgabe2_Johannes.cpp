#include "fcpp.hh"

const int ggroesse{ 10 }; // globale Variable groesse
int gfeld[ggroesse];      // globale Variable vom Typ Feld enthält die Liste

// Gibt gfeld[0] bis gfeld[anzahl-1] in einer Zeile aus
void feld_ausgeben(int anzahl) {
  std::cout << "Die Liste im Feld gfeld sieht wie folgt aus: ";

  for (int i{ 1 }; i <= anzahl; ++i) {
    std::cout << gfeld[i - 1] << ' ';
  }

  std::cout << '\n';
}

void feld_bubblesort(int anzahl) {
  // Setze Variable, die angibt, ob mindestens zwei Stellen vertauscht wurden
  bool vertauscht{ false };

  while (true) {
    // Stellt sicher, dass vertauscht zu Beginn des Durchlaufs auf "false" gesetzt ist
    vertauscht = false;

    for(int i{ 1 }; i < anzahl; ++i) {

      // Prüft, ob die Zahl an der vorausgegangenen Stelle größer ist, als an der aktuellen
      if(gfeld[i - 1] > gfeld[i]) {

        // Speichert die Variable an der vorausgegangenen Stelle zwischen, da sie gleich mit der
        // Variable an der aktuellen Stelle überschrieben werden wird
        int halter{ gfeld[i - 1] };

        // Vertauscht die Variablen
        gfeld[i - 1] = gfeld[i];
        gfeld[i] = halter;

        // Hält fest, dass vertauscht wurde
        vertauscht = true;
      }
    }

    // Beendet die Schleife, falls in diesem Durchgang keine Werte vertauscht wurden
    if (!vertauscht)
      break;
  }
}

void feld_insertionsort(int anzahl) {
  // Bestimmt das Folgenglied, welches mit den vorausgegangenen, schon sortierten, verglichen werden
  // soll
  for(int i{ 0 }; i < anzahl; ++i) {

    // Legt das zu vergleichende Folgenglied in einer Variable ab, da es später überschrieben werden
    // wird
    int speicher{ gfeld[i] };

    for(int j{ 0 }; j < i; ++j) {

      // Bestimmt die Stelle j, an der die abgelegte Variable eingesetzt werden muss
      if(speicher < gfeld[j]) {

        // Verschiebt alle Folgenglieder j bis i - 1 um eins nach rechts, um Platz für die abgelegte
        // Variable zu schaffen; dabei wird die Zahl an der i-ten Stelle überschrieben
        for(int k{ i - 1 }; k >= j; --k) {
          gfeld[k + 1] = gfeld[k];
        }

        // Setzt die abgelegte Zahl an der Stelle j ein und beendet anschließend die Schleife
        gfeld[j] = speicher;
        break;
      }
    }
  }
}

int main(int argc, char* argv[])
{
  int anzahl = argc - 1;
  if (anzahl <= ggroesse) {
    for (int i{ 1 }; i <= anzahl; ++i) {
      gfeld[i - 1] = readarg_int(argc, argv, i);
    }

    // feld_bubblesort(anzahl);
    // feld_insertionsort(anzahl);

    feld_ausgeben(anzahl);
  } else {
    std::cout << "Bitte nicht mehr als " << ggroesse << " Werte.\n";
  }

  return 0;
}
