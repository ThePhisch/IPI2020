#include "fcpp.hh"
#include <stdio.h>

const int anzahl_symbole   = 2;   // festes Alphabet {a,b,...}
const int anzahl_zustaende = 3;   // feste Zustandsmenge {0,1,...}
const int anzahl_zeilen    = anzahl_symbole * anzahl_zustaende;
                                  // Anzahl Zeilen des Programms

typedef  int  programm[anzahl_zeilen]; // Ein Zustand pro Zeile
typedef  bool zustandsmenge[anzahl_zustaende];// Menge von Zustaenden

class dea{
  public:
    dea(programm prog, zustandsmenge akz);
          // der Startzustand ist immer gleich Zustand 0
      
    void drucke_programm();
    bool verarbeite(char  eingabe[]);
    
  private:
    programm _prog;    // letzter Spalte der Übergangstabelle
    zustandsmenge _akz; // Menge der akzeptierenden Zustände
      
    void drucke_zeile(int z_vorher, int symbol, int z_nachher );
      
    int  zeile(int zustand, int symbol);
    int  zeile_zu_zustand(int zeile);
    int  zeile_zu_symbol(int zeile);
    int  nachfolge_zustand(int zustand, int symbol);
      
    bool in_alphabet(char symbol);
};

dea::dea(programm prog_neu, zustandsmenge akz_neu){
    for(int z=0; z<anzahl_zeilen; z=z+1){
        _prog[z]=prog_neu[z];
    }
    for(int j=0; j<anzahl_zustaende; j=j+1){
            _akz[j]=akz_neu[j];
    }
}

void dea::drucke_programm(){
    std::cout << "\nDer verwendete Automat hat folgendes Programm:\n" <<  std::endl;
    for(int z=0; z<anzahl_zeilen; z=z+1){
        drucke_zeile(zeile_zu_zustand(z), zeile_zu_symbol(z), _prog[z]);
    }
    std::cout << '\n' << "Die akzeptierenden Zustände sind: " ;
    for(int zustand = 0; zustand < anzahl_zustaende; zustand = zustand+1){
        if (_akz[zustand]){std::cout << zustand << ' ';}
    }    
    std::cout << ".\n" << std::endl;  
    
}


void dea::drucke_zeile(int z_vorher, int symbol, int z_nachher ){
    std::cout << '(' << z_vorher << ',' << (char) ('a' + symbol) << ',' << z_nachher << ')' << std::endl;
}

int  dea::zeile(int zustand, int symbol){
    return zustand*anzahl_symbole + symbol;
};

int  dea::zeile_zu_zustand(int zeile)   {
    return zeile/anzahl_symbole;          
};

int  dea::zeile_zu_symbol(int zeile)    {
    return zeile%anzahl_symbole;           
};

int  dea::nachfolge_zustand(int zustand, int symbol){
    return _prog[zeile(zustand, symbol)];
};

bool dea::in_alphabet(char symbol){
    return (97 <= (int) symbol) and (int) symbol <= 96+anzahl_symbole;
}

bool dea::verarbeite(char*  eingabe){
    int zustand = 0;
    for (int i = 0; in_alphabet(eingabe[i]); i++) {
        zustand = _prog[zeile(zustand, (int) eingabe[i] - 97)]; 
    }
    return _akz[zustand];
}

int main(int argc, char** argv) {
    programm prog = {1, 1, 2, 2, 0, 0}; // DEA für Länge 0 mod 3
    zustandsmenge akz = {true, false, false};  // nur Zustand 0 ist akzeptierend
    dea automat(prog,akz);
    automat.drucke_programm();
    char* eingabe;
    char  leeres_wort[1]={0};
    
    if(argc>1) {
         eingabe=argv[1];
    }
    else{           // fängt leere Eingabe ab
          eingabe=leeres_wort;
    }
    
    if (automat.verarbeite(eingabe)){
        std::cout << "Das Eingabewort " << eingabe << " ist in der Sprache.\n";
    }
    else{
        std::cout << "Das Eingabewort " << eingabe  << " ist nicht in der Sprache.\n";
    }
    return 0;
}
