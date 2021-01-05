
#include "fcpp.hh"

const int ggroesse = 10;  // globale Variable ggroesse
int gfeld[ggroesse];    // globale Variable feld vom Typ Feld enthält die Liste

void feld_ausgeben   (int anzahl)
{  // Gibt gfeld[0] bis gfeld[anzahl-1] in einer Zeile aus
    std::cout << "Die Liste im Feld gfeld sieht wie folgt aus: ";
    for ( int i = 1; i <= anzahl; i = i+1 )
           std::cout << gfeld[i-1] << " ";
    std::cout << std::endl;
}

void feld_bubblesort ( int anzahl );

void feld_insertionsort ( int anzahl );

int main( int argc, char *argv[] ){
    int anzahl = argc-1;             // anzahl ist Anzahl der eingegebenen Listenelemente
    if ( anzahl <= ggroesse ){
         for ( int i = 1; i <= anzahl; i = i+1 ) // trage die Liste in gfeld ein
            gfeld[i-1] = readarg_int( argc, argv, i );
         //feld_bubblesort( anzahl );
         feld_insertionsort( anzahl );
         feld_ausgeben( anzahl );
    }
    else  std::cout << "Bitte nicht mehr als " << ggroesse << " Werte." <<  std::endl;
}



