#include <string>


typedef struct element {
  int value;
  struct element* next;
  struct element* prev;
} element;

element* new_element(int value) {
  element* e = new element;
  e->next = NULL;
  e->prev = NULL;
  e->value = value;
  return e;
}

typedef struct list {
  struct element* start;
  struct element* end;
  int length;
} list;

list new_list() {
  list l;
  l.start = NULL;
  l.end = NULL;
  l.length = 0;
  return l;
}

void append(list& l, element* e) {
  if (l.length == 0) {
    l.start = e;
    l.end = e;
    l.length = 1;
    e->next = NULL;
    e->prev = NULL;
  } else {
    l.end->next = e;
    e->prev = l.end;
    e->next = NULL;
    l.end = e;
    l.length++;
  }
}

void prepend(list& l, element* e) {
  if (l.length == 0)
    append(l, e);
  else {
    l.start->prev = e;
    e->next = l.start;
    e->prev = NULL;
    l.start = e;
    l.length++;
  }
}

void insert(list& l, element* e, int index) {
  if (index <= 0)
    prepend(l, e);
  else if (index >= l.length)
    append(l, e);
  else {
    element* curr = l.start;
    while (index > 0) {
      curr = curr->next;
      index--;
    }
    curr->prev->next = e;
    e->next = curr;
    e->prev = curr->prev;
    curr->prev = e;
    l.length++;
  }
}
void insert(list& l, int value, int index) {
  insert(l, new_element(value), index);
}

element* extract(list& l, element* e) {
  if (e == l.start) {
    l.start = e->next;
  }
  if (e == l.end) {
    l.end = e->prev;
  }
  if (e->next != NULL)
    e->next->prev = e->prev;
  if (e->prev != NULL)
    e->prev->next = e->next;
  l.length--;
  return e;
}

element* extract(list& l, int index) {
  element* e;
  if (index <= 0)
    e = extract(l, l.start);
  else if (index >= l.length - 1)
    e = extract(l, l.end);
  else {
    e = l.start;
    while (index > 0) {
      e = e->next;
      index--;
    }
    e = extract(l, e);
  }
  return e;
}


std::string to_string(const list& l) {
  if (l.length == 0) {
    return "length = 0";
  }
  std::string str = "";
  element* curr = l.start;
  str += std::to_string(curr->value) + ", ";
  while (curr->next != NULL) {
    curr = curr->next;
    str += std::to_string(curr->value) + ", ";
  }
  str += "length = " + std::to_string(l.length);
  return str;
}

void merge(list& left, list& right) {
  if (left.length == 0) {
    left.start = right.start;
    left.end = right.end;
    left.length = right.length;
  }
  else if (right.length == 0) {
    right.start = left.start;
    right.end = left.end;
    right.length = left.length;
  } else {
    left.end->next = right.start;
    right.start->prev = left.end;
    left.length += right.length;
    right.length = left.length;
    left.end = right.end;
    right.start = left.start;
  }
}

list from_array(int arr[], int length) {
  list l = new_list();
  for (int i = 0; i < length; i++) {
    append(l, new_element(arr[i]));
  }
  return l;
}