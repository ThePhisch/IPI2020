// Anton, Johannes, Maxi
// Bei Kamal
#include "fcpp.hh"

float determinante_float(float a, float b, float c, float d)
{
  return a*d - b*c;
}

double determinante_double(double a, double b, double c, double d) 
{
  return a*d - b*c;
}

int main(int argc, char *argv[])
{
  // Fügen Sie hier Ihren Code ein, zum Beispiel
  // print(teiler(readarg_int(argc,argv,1),readarg_int(argc,argv,2))); 
  print(
    determinante_float(
      float(readarg_double(argc,argv,1)),
      float(readarg_double(argc,argv,2)),
      float(readarg_double(argc,argv,3)),
      float(readarg_double(argc,argv,4))));
  print(
    determinante_double(
      readarg_double(argc,argv,1),
      readarg_double(argc,argv,2),
      readarg_double(argc,argv,3),
      readarg_double(argc,argv,4)));
  return(0);
}
