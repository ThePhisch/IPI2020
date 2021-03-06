#include "fcpp.hh"

/*
 * zur c) Die Funktion quadrat() wird in allen drei Fällen dreimal aufgerufen.
 *        Für die andere Methode finden beim Exponenten 8 vier Multiplikation,
 *        sonst sechs statt.
 */

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
  print(expo(2, 8));
  print(expo(2, 11));
  print(expo(2, 15));
  return 0;
}

