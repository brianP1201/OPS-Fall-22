// list/list.c
//
// Implementation for linked list.
//
// <Brian Paul>

#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/* Functions for allocating and freeing lists. By using only these functions,
 * the user should be able to allocate and free all the memory required for
 * this linked list library. */
list_t *list_alloc(){
  return malloc(sizeof(list_t));
}

void list_free(list_t* l) {
  free(l);
}

/* Prints the list in some format. */
void list_print(list_t *l) {
  node_t *curr = l->head;
  while(curr){
    if (curr->next) {
      printf("%d -> ", curr->value);
    } else {
      printf("%d", curr->value);
      printf("\n");
    }
    curr = curr->next;
  }
  
}

/* Returns the length of the list. */
int list_length(list_t *l) {
  node_t *curr = l->head;
  int len = 0;
  while (curr){
    len++;
    curr = curr->next;
  }
  return len;
}

/* Methods for adding to the list. */
void list_add_to_back(list_t *l, elem value) {
  int count = 1;
  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = value;
  node_t *prev = l->head;
  node_t *curr = l->head->next;
  while(prev){
    if (count == list_length(l)){
      prev->next = new_node;
      new_node->next = curr;
      break;
    }
    prev = curr;
    curr = curr->next;
    count++;
  }
}
void list_add_to_front(list_t *l, elem value) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = value;
  node_t *curr = l->head;
  l->head = new_node;
  l->head->next = curr;
}
void list_add_at_index(list_t *l, elem value, int index) {
  
  if(index > list_length(l)-1){
    list_add_to_back(l, value);
  } else {
    int count = 1;
    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = value;
    node_t *prev = l->head;
    node_t *curr = l->head->next;
    while(prev){
      if (count == index){
        prev->next = new_node;
        new_node->next = curr;
        break;
      }
      prev = curr;
      curr = curr->next;
      count++;
    }
  }
  
  }  // adds to end of list if out of bounds

/* Methods for removing from the list. Returns the removed element, or -1 for empty list */
elem list_remove_from_back(list_t *l){
  if(list_length(l)==0){
    return -1;
  } else{
    int count = 1;
    node_t *prev = l->head;
    node_t *curr = l->head->next;
    while (prev) {
      if (count == list_length(l)-1 && curr){
        int popped_node = curr->value;
        prev->next = curr->next;
        return popped_node;
      }
      prev = curr;
      curr = curr->next;
      count++;
    }
  }

  
}


elem list_remove_from_front(list_t *l) {
  if(list_length(l)==0){
    return -1;
  } 
  
  node_t *prev = l->head;
  l->head = l->head->next;
  return prev->value;
}

elem list_remove_at_index(list_t *l, int index) {
  if(list_length(l)==0){
    return -1;
  }
  
  int count = 1;
  node_t *prev = l->head;
  node_t *curr = prev->next;
  while (prev) {
    if (count == index && curr){
      int popped_node = curr->value;
      prev->next = curr->next;
      return popped_node;
    }
    prev = curr;
    curr = curr->next;
    count++;
  }
}

/* Checks to see if the given element exists in the list. */
bool list_is_in(list_t *l, elem value){
  if(l->head){
    node_t *curr = l->head;
    while(curr) {
      if (curr->value == value) {
        return true;
      }
      curr = curr->next;
    }
    return false;
  }
  return false;
}

/* Returns the element at the given index, or -1 if empty or out of bounds */
elem list_get_elem_at(list_t *l, int index){
  if(l->head){
    int count = 0;
    node_t *curr = l->head;
    while(curr) {
      if(count == index){
        return curr->value;
      }
      curr = curr->next;
      count++;
    }
  }
  return -1;
}

/* Returns the index at which the given element appears, or -1 if not found */
int list_get_index_of(list_t *l, elem value) {
  if(l->head) {
    int count = 0;
    node_t *curr = l->head;
    while (curr){
      if (curr->value == value){
        return count;
      }
      curr = curr->next;
      count++;
    }
  }
  return -1;
}