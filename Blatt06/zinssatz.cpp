// Anton, Johannes, Maxi
// Bei Kamal
#include "fcpp.hh"


float zins_float(float z, int n) 
{
  return float(pow(1+z/n,n))-1;
}

double zins_double(double z, int n) 
{
  return double(pow(1+z/n,n))-1;
}

int main(int argc, char *argv[]) 
{
  // Fügen Sie hier Ihren Code ein, zum Beispiel
  // print(teiler(readarg_int(argc,argv,1),readarg_int(argc,argv,2)));
  int n [6] = {1,12,365,365*24,365*24*60,365*24*60*60};
  float z = 0.06;
  for (int i = 0; i < 6; i++)
  {
    print("===");
    print("n =", n[i],0);
    print(zins_float(z,n[i]), zins_float(z,n[i]) - (exp(z)-1),0);
    print(zins_double(z,n[i]), zins_double(z,n[i]) - (exp(z)-1),0);
  }
  
  return(0);
}
