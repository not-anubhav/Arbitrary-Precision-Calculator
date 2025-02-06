#include "apc.h"

int dl_insert_first(Dlist **head, Dlist **tail, int data)
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
        if(*head == NULL && *tail == NULL)
        {
            /* update the head and tail with new node address */
                *head = new; 
                *tail = new;
                return SUCCESS;
        }
    /* List is not empty */
        Dlist *temp = *head; // Take a temp pointer

        *head = new; // Update the head with new node address 
        new->next = temp; // Update the next of new with next node address 
        temp->prev = new; // Update the previous of next node with new node address 
        return SUCCESS;
}
