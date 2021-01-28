#ifndef LISTS_H
#define LISTS_H

#include <string>

typedef struct element {
  int value;
  struct element* next;
  struct element* prev;
} element;

element* new_element(int value);

typedef struct list {
  struct element* start;
  struct element* end;
  int length;
} list;

list new_list();
void append(list& l, element* e);
void prepend(list& l, element* e);
void insert(list& l, element* e, int index);
void insert(list& l, int value, int index);
std::string to_string(const list& l);
void merge(list& left, list& right);
element* extract(list& l, element* e);
element* extract(list& l, int index);
list from_array(int arr[], int length);

#endif //LISTS_H