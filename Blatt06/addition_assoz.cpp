// Anton, Johannes, Maxi
// Bei Kamal
#include "fcpp.hh"


float differenz(float base, int n) 
{
  float a = float(pow(base,n));
  float b = float(pow(-base,n));
  float c = float(pow(base,-n));
  return ((a+b)+c) - (a+(b+c));
}

int main(int argc, char *argv[]) 
{
  // Fügen Sie hier Ihren Code ein, zum Beispiel
  // print(teiler(readarg_int(argc,argv,1),readarg_int(argc,argv,2)));
  int basis = 10;
  print(basis);
  for (int i = 1; i < 15; i++)
  {
    print(i, differenz(basis,i), 0);
  }
  
  return(0);
}
