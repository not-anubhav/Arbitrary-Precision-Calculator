#include "apc.h"

int dl_delete_first(Dlist **head, Dlist **tail)
{
    /* If List is Empty */
        if(*head == NULL || *tail == NULL)
        {
                return FAILURE;
        }
    /* List is not empty */
        else
        {
                if(*head == *tail) // If both head and tail are pointing to same node that means only one node is present
                {
                        free(*head); // Delete the node 
                        *head = *tail = NULL; // Assign NULL to head and tail
                        return SUCCESS;
                }
                /* If list contains multiple node */
                Dlist *temp = *head; // Take a Temp pointer containing head address
                *head = temp->next; /* Store the 2nd node address in the head*/
                free(temp); /* Delete the first node */
                if(*head != NULL)
                {
                        (*head)->prev = NULL; // Update the new first node prev with NULL
                }
        }
        return SUCCESS;
}