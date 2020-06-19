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

node_t* create_list()
{
    node_t* head = malloc(sizeof(node_t));
    head->data = 0;
    head->next = 0;
    return head;
}

void add_data(node_t** head, void* data)
{
    // add to first node if no data there
    if(!(*head)->data){
        (*head)->data = data;
        return;
    }

    // else append it to the start
    node_t* node = malloc(sizeof(node_t));
    node->data = data;
    node->next = (*head);
    (*head) = node;
}

void free_list(node_t** head)
{
    node_t* cur = *head;
    node_t* temp;
    while(cur)
    {
        temp = cur->next;
        free(cur->data);
        free(cur);
        cur = temp;
    }
}

void for_each(node_t** head, void(*func)(void*))
{
    node_t* cur_node = *head;
    while(cur_node)
    {
        func(cur_node);
        cur_node = cur_node->next;
    }
}



static void
swap_nodes(node_t* p1, node_t* p2)
{ 
    void* data = p1->data;
    p1->data = p2->data; 
    p2->data = data;
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
sort_list(node_t** head, int(*comp)(void*, void*))
{ 
    if(!comp)
        default_compare;

    node_t* curr = *(head);

    while(curr->next)
    {
        node_t* next = curr->next;

        while(next)
        {
            if (comp(curr->data, next->data)!=0)
            {
                swap_nodes(next, curr);
            }
            next = next->next;
        }
        curr = curr->next;
    }
}

void remove_node(node_t** prev_node, node_t** node)
{
    //prev_node->next = node->next;
   // free(node->data);
    //free(node);
}