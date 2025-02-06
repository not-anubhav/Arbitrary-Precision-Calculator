#include "apc.h"

int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
    /* Creating new node */
        Dlist *new = malloc(sizeof(Dlist)); // Allocate the memory
        if(new == NULL) // Validate the allocation
        {
                return FAILURE;
        }
        /* update the data, prev and next of new node */
        new->data = data;
        new->prev = NULL;
        new->next = NULL;
    /* If List is Empty */
        if(*head == NULL)
        {
            /* update the head and tail with new node address */
                *head = new;
                *tail = new;
                return SUCCESS;
        }
    /* List is not empty */
        new->prev = *tail; // Update previous of new with tail(which contains last node address)
        (*tail)->next = new; // Update next of last node with new node address
        *tail = new; // Update tail to point at new node making new node as last node
        return SUCCESS;
}
