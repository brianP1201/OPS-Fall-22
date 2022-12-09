#include <stdio.h>
#include "list.h"

int main() 
{
  printf("Write your Tests for your linked list implementation\n");
  
  list_t *mylist;
  
  mylist = list_alloc();

  list_add_to_front(mylist, 22);
  list_add_to_back(mylist, 3);
  list_add_to_back(mylist, 24);
  list_add_to_back(mylist, 33);
  list_add_to_back(mylist, 6);
  list_add_to_front(mylist, 44);

  list_print(mylist);

  list_add_at_index(mylist, 8, 2);
  list_add_at_index(mylist, 21, 3);
  list_print(mylist);

  printf("Removing element %d from back\n", list_remove_from_back(mylist));
  printf("Removing element %d from front\n", list_remove_from_front(mylist));

  printf("Removing element %d from index 3\n", list_remove_at_index(mylist, 3));
  printf("Is element 22 in my list? %d\n", list_is_in(mylist, 22));
  printf("Is element 3 in my list? %d\n", list_is_in(mylist, 3));
  printf("Is element 44 in my list? %d\n", list_is_in(mylist, 44));

  printf("Element at index 0 is %d\n", list_get_elem_at(mylist, 0));
  printf("Element at index 2 is %d\n", list_get_elem_at(mylist, 2));
  printf("Element at index 4 is %d\n", list_get_elem_at(mylist, 4));
  printf("Element at index 9 is %d\n", list_get_elem_at(mylist, 9));

  printf("Index of element 21 is %d\n", list_get_index_of(mylist, 21));
  printf("Index of element 3 is %d\n", list_get_index_of(mylist, 3));
  printf("Index of element 52 is %d\n", list_get_index_of(mylist, 52));

  list_print(mylist);
}
