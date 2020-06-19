#include "LinkedList.h"

LinkedList* create_list()
{
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    *list = (Node*)malloc(sizeof(Node));
    Node* new_node = *list;
    new_node->data = 0;
    new_node->next = 0;
    return list;
}


void add_data(LinkedList* list, void* data)
{
    Node* head = *list;
    Node* new_node;

    if (head->data == 0)
    {
        head->data = data;
    }
    else
    {
        new_node = malloc(sizeof (Node));
        new_node->data = data;
        new_node->next = head;
        *list = new_node;
    }
}

void free_list(LinkedList* list)
{
    Node* cur_node = *list;
    Node* tmp_node;

    while(cur_node)
    {
        tmp_node = cur_node->next;
        free(cur_node);
        cur_node = tmp_node;
    }
    
    free(list);
}

void foreach(LinkedList* list, void(*func)(Node*))
{
    Node* cur_node = *list;
    while(cur_node)
    {
        func(cur_node);
        cur_node = cur_node->next;
    }
}