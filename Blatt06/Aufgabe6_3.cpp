/*
 * Gegen Angriffe kann man sich wehren, gegen Lob ist man machtlos.
 * - Sigmund Freud
 */

#include "fcpp.hh"

// Bestimmt, ob zahl prim ist
bool prim(int zahl)
{
  if (zahl == 1)
    return false;

  int index{2};
  int wurzel{sqrt(static_cast<double>(zahl))};

  while (index <= wurzel)
    {
      if (zahl % index == 0)
        return false;

      ++index;
    }


  return true;
}

// Bestimmung der Primzahlen im Intervall [untere, obere] mit einer while-Schleife
int prim_anzahl_while(int untere, int obere)
{
  int anzahl{0};
  int &index{untere};

  while (index <= obere)
    {
      if (prim(index))
        ++anzahl;

      ++ index;
    }
  return anzahl;
}

// Bestimmung der Primzahlen im Intervall [untere, obere] mit einer for-Schleife
int prim_anzahl_for(int untere, int obere)
{
  int anzahl{0};
  int &index{untere};

  for (index; index <= obere; ++index)
    {
      if (prim(index))
        ++anzahl;
    }
  return anzahl;
}

int prim_anzahl_goto(int untere, int obere)
{
  int anzahl{0};
  int &index{untere};

 kopf:
  if (index > obere)
    return anzahl;

  if (prim(index))
    ++anzahl;
  ++index;

  goto kopf;
}

int main()
{
  print(prim_anzahl_for(1, 100));
  print(prim_anzahl_while(1, 100));
  print(prim_anzahl_goto(1, 100));
  return 0;
}
