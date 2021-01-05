
#include "fcpp.hh"

const int ggroesse = 10; // globale Variable ggroesse
int gfeld[ggroesse];     // globale Variable feld vom Typ Feld enthält die Liste

void feld_ausgeben(int anzahl)
{ // Gibt gfeld[0] bis gfeld[anzahl-1] in einer Zeile aus
    std::cout << "Die Liste im Feld gfeld sieht wie folgt aus: ";
    for (int i = 1; i <= anzahl; i = i + 1)
    {
        std::cout << gfeld[i - 1] << " ";
    }
    std::cout << std::endl;
}

void feld_bubblesort(int anzahl)
/*
Implementiert den Bubblesort-Algorithmus wie in der Aufgabe beschrieben
*/
{
    bool altered = true;
    while (altered)
    {
        altered = false;
        for (int i = 0; i < anzahl - 1; i = i + 1)
        {
            if (gfeld[i] > gfeld[i + 1])
            {
                int swap = gfeld[i + 1];
                gfeld[i + 1] = gfeld[i];
                gfeld[i] = swap;
                altered = true;
            }
        }
    }
    return;
}

void feld_insertionsort(int anzahl)
/*
Implementiert den Insertionsort-Algorithmus wie in der Aufgabe beschrieben
*/
{
    for (int i = 1; i < anzahl; i = i + 1)
    {
        int value = gfeld[i];
        int loc = i;
        for (int j = 0; j < i; j = j + 1)
        // findet den index, an dem der Wert eingefügt werden soll
        {
            if (gfeld[j] > value)
            {
                loc = j;
                break;
            }
        }
        for (int j = i - 1; j >= loc; j = j - 1)
        // verschiebt teil der sortierten teilfolge um eins nach rechts
        {
            if (j >= loc)
            {
                gfeld[j + 1] = gfeld[j];
            }
        }
        gfeld[loc] = value;
    }
}

int main(int argc, char *argv[])
{
    int anzahl = argc - 1; // anzahl ist Anzahl der eingegebenen Listenelemente
    if (anzahl <= ggroesse)
    {
        for (int i = 1; i <= anzahl; i = i + 1) // trage die Liste in gfeld ein
        {
            gfeld[i - 1] = readarg_int(argc, argv, i);
        }
        // feld_bubblesort(anzahl);
        feld_insertionsort(anzahl);
        feld_ausgeben(anzahl);
    }
    else
        std::cout << "Bitte nicht mehr als " << ggroesse << " Werte." << std::endl;
}
