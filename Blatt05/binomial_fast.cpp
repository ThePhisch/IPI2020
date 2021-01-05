#include "fcpp.hh"

int mult_intervall(int a, int b) {
  return cond(a<=0,0,
  cond(a>b,0,
  cond(a==b,a,
  a*mult_intervall(a+1,b))));
}

int fak(int a, int b) {
  return cond(b==0,1,mult_intervall(a,b));
}

int binomial_fast(int n, int k) {
  return cond(k<0,0,
  cond(k>n,0,
  fak(1,n) / (fak(1,k) * fak(1,n-k))
  ));
}

int main(int argc, char *argv[]) {
  // Fügen Sie hier Ihren Code ein, zum Beispiel
  print(binomial_fast(readarg_int(argc, argv, 1),readarg_int(argc, argv, 2)));
  return(0);
}
