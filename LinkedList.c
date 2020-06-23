/*  
=======================================
$File: LinkedList.c $
$Date: 18/06/2020 $
$Revision: 0.5 $
$Creator: Joe Kenyon $
$Notice: $
=======================================
*/

#include "LinkedList.h"

List
create_list()
{
    List list;
    list.head = 0;
    list.size = 0;

    list.push   = &ll_push;
    list.get    = &ll_get;
    list.remove = &ll_remove;
    list.free   = &ll_free;
    list.sort   = &ll_sort;
    list.print  = &ll_print;
    list.createNode = &ll_createNode;
    list.getHead    = &ll_getHead;
    list.getSize    = &ll_getSize;
    
    return list;
}


void 
ll_push(List* this, void* data)
{

    // create node
    node_t* node = malloc(sizeof(node_t));
    node->data   = data;

    this->size++;

    // add to first node if no data there
    if(! this->head){
        this->head = node;
        return;
    }

    // else, append to head
    node->next =  this->head;
    this->head = node;
}

void*
ll_get(List* this, int index)
{
    node_t* cur_node = this->head;
    int cur_index = 0;

    while(cur_node && cur_index++ != index)
        cur_node = cur_node->next;

    return cur_node->data;
}

void
ll_remove(List* this, int index)
{
    node_t* curr_node  = this->head;
    node_t* prev_node  = 0;
    
    int cur_index = 0;
    while(curr_node)
    {
        node_t* next_node = curr_node->next;
        if(cur_index++ == index)
        {
            free(curr_node->data);
            free(curr_node);

            if(prev_node)
                prev_node->next = next_node;
            else
                this->head = next_node;
            this->size--;
            return;
        }
        else
        {
            prev_node = curr_node;
            curr_node = next_node;
        }
    }
}

void
ll_free(List* this)
{
    node_t* cur = this->head;
    node_t* temp;
    while(cur)
    {
        temp = cur->next;
        free(cur->data);
        free(cur);
        cur = temp;
    }
}

void
ll_print(List* this, void(*func)(void*))
{
    node_t* cur = this->head;
    while(cur)
    {
        func(cur->data);
        cur = cur->next;
    }
}

static int
default_compare(void* p1, void* p2)
{
    // assume data is int pointers
    int* n1 = (int*)p1;
    int* n2 = (int*)p2;
    return (*n1 > *n2);
}

void
ll_sort(List* this, int(*comp)(void*, void*))
{
    if(!comp)
        default_compare;

    node_t* curr = this->head;

    while(curr->next)
    {
        node_t* next = curr->next;

        while(next)
        {
            if (comp(curr->data, next->data)!=0)
            {
                // swap nodes -> p1 = curr, p2 = next
                void* data = curr->data;
                curr->data = next->data; 
                next->data = data;
            }
            next = next->next;
        }
        curr = curr->next;
    }
}


node_t* ll_getHead(List* list)
{
    return list->head;
}

size_t ll_getSize(List* list)
{
    return list->size;
}

node_t* ll_createNode(void* data)
{
    node_t* node  = malloc(sizeof(node_t));
    node->data    = data;
    node->getData = &ll_getData;
    node->getNext = &ll_getNext;
    node->setData = &ll_setData;
    node->setNext = &ll_setNext;
}

node_t* ll_getNext(node_t* this)
{
    return this->next;
}

void* ll_getData(node_t* this)
{
    return this->data;
}

void ll_setData(node_t* this, void* data)
{
    this->data = data;
}

void ll_setNext(node_t* this, node_t* next)
{
    this->next = next;
}