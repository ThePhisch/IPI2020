//#include "fcpp.hh"
#include <iostream>

class IntList
{
public:
	// Konstruktor, erzeugt eine leere Liste
	IntList();

	// Copy-Konstruktor, erzeuge deep copy
	IntList(const IntList &other);

	// Destruktor, loescht gesamten Listeninhalt
	~IntList();

	// Zuweisungsoperator
	IntList &operator=(const IntList &other);

	// Gibt die Liste aus
	void print();

	// Gibt zurueck, ob die Liste leer ist
	bool isEmpty();

	// Gibt Anzahl der Elemente zurueck
	int getCount();

	// Die folgenden Methoden sind Aufgabenteil a zu implementieren:
	// Gibt den Wert des Elements an der Position 'position' zurueck
	int getElement(int position);

	// Füge den Wert 'wert' nach der Position 'position' ein,
	// Position -1 steht für Einfügen am Listenanfang
	void insert(int wert, int position);

	// Löscht das Element an der Position 'position'
	void remove(int position);

private:
	// Ein Listenelement
	struct IntListElem
	{
		IntListElem *next;
		int value;
	};

	// Anzahl Elemente in der Liste
	int count;

	// Zeiger auf erstes Element der Liste
	IntListElem *first;

	void discard();

	IntListElem *copyList(IntListElem *otherFirst);
};

IntList::IntList()
{
	first = 0;
	count = 0;
}

// Copy-Konstruktor, erzeuge deep copy
IntList::IntList(const IntList &other)
{
	count = other.count;
	IntListElem *f = other.first;
	first = copyList(f);
}

// Destruktor, loesche alle Elemente
IntList::~IntList()
{
	discard();
}

// Zuweisungsoperator
IntList &IntList::operator=(const IntList &other)
{
	if (this != &other)
	{
		discard();
		count = other.count;
		IntListElem *f = other.first;
		first = copyList(f);
	}
	/*
	Der Fall, dass die Objekte links und rechts identisch sind, muss
	abgefangen werden, denn sonst würde die Methode "discard" die
	Elemente links und rechts löschen und es gäbe keine Listenelemente
	mehr, die kopiert werden können	
	 */
}

void IntList::print()
{
	std::cout << "Die Anzahl der Elemente ist " << count << ". Die Elemente sind: ( "; // << std::endl;
	int i = 0;
	for (IntListElem *p = first; p != 0; p = p->next)
	{
		std::cout << i << ": " << p->value << " "; // << std::endl;
		i++;
	}
	std::cout << ")" << std::endl;
}

bool IntList::isEmpty()
{
	return (count == 0);
}

int IntList::getCount()
{
	return count;
}

int IntList::getElement(int position)
{
	IntListElem *curr = first;
	for (int i = 0; i < position; i++)
	{
		curr = curr->next;
	}
	return curr->value;
}

void IntList::insert(int element, int position = 0)
{
	IntListElem *e = new IntListElem;
	e->next = NULL;
	e->value = element;
	if (count == 0)
	{
		// list was empty, add first item
		first = e;
	}
	else
	{
		// prepend
		if (position <= 0)
		{
			e->next = first;
			first = e;
		}
		// append
		else if (position > count)
		{
			IntListElem *curr = first;
			for (int i = 0; i < count - 1; i++)
			{
				curr = curr->next;
			}
			curr->next = e;
		}
		// insert
		else
		{
			IntListElem *curr = first;
			for (int i = 0; i < position - 1; i++)
			{
				curr = curr->next;
			}
			IntListElem *relink = curr->next;
			curr->next = e;
			e->next = relink;
		}
	}
	count++;
}

void IntList::remove(int position)
{
	if (count == 0)
	{
		// list was empty, don't do anything
		return;
	}
	else
	{
		// delete first element
		if (position <= 0)
		{
			IntListElem *temp = first->next;
			delete first;
			first = temp;
		}
		// delete last element
		else if (position > count)
		{
			IntListElem *curr = first;
			for (int i = 0; i < count - 1; i++)
			{
				curr = curr->next;
			}
			delete curr->next;
			curr->next = NULL;
		}
		// insert
		else
		{
			IntListElem *curr = first;
			for (int i = 0; i < position - 1; i++)
			{
				curr = curr->next;
			}
			IntListElem *relink = curr->next->next;
			delete curr->next;
			curr->next = relink;
		}
	}
	count--;
}

// erzeugt eine tiefe Kopie der internen Liste
IntList::IntListElem *IntList::copyList(IntListElem *otherFirst)
{
	IntListElem *newFirst = new IntListElem();
	newFirst->value = otherFirst->value;
	IntListElem *temp = newFirst;

	for (IntListElem *cursor = otherFirst->next; cursor; cursor = cursor->next)
	{
		temp->next = new IntListElem();
		temp->next->value = cursor->value;
		temp->next->next = NULL;
		temp = temp->next;
	}
	return newFirst;
}

// leere die interne Liste
void IntList::discard()
{
	count = 0;
	IntListElem *curr = first;
	for (int i; i < count; i++)
	{
		IntListElem *temp = curr->next;
		delete curr;
		curr = temp;
	}
}

int main()
{
	IntList list;
	std::cout << "Liste empty? " << list.isEmpty() << std::endl;
	std::cout << "Anzahl Elemente: " << list.getCount() << std::endl;

	list.insert(30);
	list.insert(20);
	list.insert(10);
	list.print();
	list.insert(69, 5);
	list.print();

	// int pos = 1;
	// std::cout << "Element an Position " << pos << ": " << list.getElement(pos) << std::endl;

	list.remove(1);
	list.print();

	list.insert(20, 1);
	list.print();

	IntList copy(list);
	copy.print();

	copy.remove(0);
	copy.print();

	copy = list;
	copy.print();

	return 0;
}
