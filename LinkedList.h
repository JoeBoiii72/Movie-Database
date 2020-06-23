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

#include "stddef.h"


typedef struct node_t node_t;
typedef struct List List;

struct node_t
{
  void*   data;
  node_t* next;
  // not using this shit
  /*
  node_t* (*getNext)(node_t**);
  node_t* (*getData)(node_t**);
  void    (*setData)(node_t**, void*);
  void    (*setNext)(node_t**, node_t**);
  void    (*iterate)(node_t**);
  */
};

struct List
{
  node_t* head;
  void    (*push  )(List*, void*);
  void*   (*get   )(List*, int  );
  void    (*remove)(List*, int  );
  void    (*free  )(List*       );
  void    (*sort  )(List*, int(*comp)(void*, void*));
  void    (*print )(List*, void(*func)(void*));
  node_t* (*createNode)(void*);
  node_t* (*getHead)(List*);
};

List    create_list();

// list functions
void    ll_push      (List* this, void* data);
void*   ll_get       (List* this, int index);
void    ll_remove    (List* this, int index);
void    ll_free      (List* this);
void    ll_sort      (List* this, int(*comp)(void*, void*));
void    ll_print     (List*, void(*func)(void*));
node_t* ll_createNode(void* data);
node_t* ll_getHead   (List* this);
size_t  ll_getSize   (List* this);


// node functions
/*
node_t* ll_getNext   (node_t** this);
void*   ll_getData   (node_t** this);
void    ll_setData   (node_t** this, void* data);
void    ll_setNext   (node_t** this, node_t** next);
void    ll_iterate   (node_t** this);*/

#endif