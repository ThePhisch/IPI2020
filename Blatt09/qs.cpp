#include "fcpp.hh"
#include "lists.h"

list l;

int main()
{
	// Beispiel-Liste
	list l = from_array((int[]){-1, 8, 0, 5, 3, -4, 11}, 7);
	print(to_string(l));
	// Sortieren mit Quicksort
	//quicksort(l);
	print(to_string(l));
	return 0;
}

