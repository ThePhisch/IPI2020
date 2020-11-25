#include "iostream"
#include "fcpp.hh"

bool ungerade(int zahl)
{
  return zahl % 2 == 1;
}

int mS(int a, int b)
{
  print("weitere Multiplikation");
  return a * b;
}

int quadrat(int zahl)
{
  print("mult in quadrat()");
  return mS(zahl, zahl);
}

int expo(int basis, int exponent)
{
  return cond(exponent < 0, 0,
              cond(exponent == 0, 1,
                   cond(ungerade(exponent), mS(basis, expo(basis, exponent - 1)),
                        quadrat(expo(basis, exponent / 2)))));
}

int main()
{
  return print(expo(2, 15));
}

// quadrat wird in allen drei Fällen dreimal aufgerufen
