#include "fcpp.hh"
#include "lists.h"

int counter = 0;

list quicksort(list& l){
	counter++;
	if(l.length <= 1) {
		return l;
	}
	int pivot = l.start->value;
	int lowerArray[l.length] = {};
	int sameArray[l.length] = {pivot};
	int higherArray[l.length] = {};
	list lower = from_array((int*) lowerArray, 0);
	list same = from_array((int*) sameArray, 1);
	list higher = from_array((int*) higherArray, 0);
		
	for(element* current = l.start->next; current != 0; current = current->next) {
		if(current->value < pivot){
			current = current->prev;
			append(lower, extract(l, current->next));
		}
		else if(current->value == pivot){
			current = current->prev;
			append(same, extract(l, current->next));
		}
		else {
			current = current->prev;
			append(higher, extract(l, current->next));
		}
	}
	
	list sortedLower = quicksort(lower);
	list sortedHigher = quicksort(higher);
	merge(sortedLower, same);
	merge(same, sortedHigher);
	l = same;
	return same;
}

int main() {
	// Beispiel-Liste
	int myArray[7] = {3, -1, 0, -4, 5, 8, 11};
	list l = from_array((int*) myArray, 7);
	print(to_string(l));

	// Sortieren mit Quicksort
	quicksort(l);
	print(to_string(l), "Ausführungen: ", counter, 0);

	return 0;
}
