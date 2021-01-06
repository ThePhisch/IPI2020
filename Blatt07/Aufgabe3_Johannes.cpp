#include "fcpp.hh"

const int gnmax{ 10 };
const int ggroesse{ (gnmax * (gnmax + 1)) / 2};
int gfeld[ggroesse];

// Gibt für ein beliebiges Tupel (n, k) die Stelle im Array zurück
int pos(int n, int k) {
  return ((n * (n + 1)) / 2) + k;
}

void populateArray() {
  // Iteriert über alle möglichen n
  for(int n{ 0 }; n <= gnmax; ++n) {

    // Iteriert pro n über alle möglichen k
    for(int k{ 0 }; k <= n; ++k) {

      // Berechnet den Binomialkoeffizienten von (n, k) und schreibt ihn an die entsprechende
      // Stelle in "gfeld"
      if( (k == n) || (k == 0) ) {
        gfeld[pos(n, k)] = 1;
      } else {
        gfeld[pos(n, k)] = gfeld[pos(n - 1, k - 1)] + gfeld[pos(n - 1, k)];
      }
    }
  }
}

int main(int argc, char** argv)
{
  // Berechnet alle Einträge von "gfeld"
  populateArray();

  int n{ readarg_int(argc, argv, 1) };
  int k{ readarg_int(argc, argv, 2) };

  if( n >= k) {
    std::cout << gfeld[pos(n, k)] << '\n';
  } else {
    std::cout << "Bitte n > k wählen." << '\n';
  }

  return 0;
}
