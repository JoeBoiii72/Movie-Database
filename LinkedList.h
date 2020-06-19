#ifndef __LINKED_LIST__H_
#define __LINKED_LIST__H_

struct Node
{
  void*       data;
  struct Node* next;
};

typedef struct Node* LinkedList;
typedef struct Node  Node;

LinkedList* create_list();
void        add_data(LinkedList* list, void* data);
void        free_list(LinkedList* list);
void        foreach(LinkedList* list, void(*func)(Node*));

#endif