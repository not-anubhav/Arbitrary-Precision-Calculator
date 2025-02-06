#include "apc.h"

int dl_delete_list(Dlist **head, Dlist **tail)
{
    /* If List is Empty */
        if(*head == NULL && *tail == NULL)
        {
                return FAILURE;
        }
    /* List is not empty */
        if(*head == *tail) // If both head and tail are pointing to same node that means only one node is present
        {
                Dlist *temp = *head; // Store the node address inside a temp pointer
                // Update the head and tail to NULL
                *head = NULL;
                *tail = NULL;
                //free the node
                free(temp);
                return SUCCESS;
        }

        if(*head != NULL)
        {
            /* Run a loop till head becomes NULL */
                while(*head != NULL)
                {
                        Dlist *temp = *head; // Take a temp pointer for each loop iteration and store new head
                        *head = temp->next; // Update the head to next node
                        free(temp); //Delete the traversed node
                }
                *tail = NULL; // At last assign NULL to tail and make the list empty
                return SUCCESS;
        }
}