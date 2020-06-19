/*  
=======================================
$File: LinkedList.h $
$Date: 18/06/2020 $
$Revision: 0.5 $
$Creator: Joe Kenyon $
$Notice: $
=======================================
*/

#ifndef __LINKED_LIST__H_
#define __LINKED_LIST__H_

struct node_t
{
  void*          data;
  struct node_t* next;
};

typedef struct node_t node_t;

node_t*   create_list();
void      add_data(node_t** head, void* data);
void      free_list(node_t** head);
void      for_each(node_t** head, void(*func)(void*));
void      sort_list(node_t** head, int(*comp)(void*, void*));
void      remove_node(node_t** prev_node, node_t** node);

#endif