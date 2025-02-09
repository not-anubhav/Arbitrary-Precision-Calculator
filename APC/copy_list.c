#include "apc.h"

int copy_list(Dlist **headR1, Dlist **tailR1, Dlist **headR3, Dlist **tailR3)
{
    /* Copy Data from R3 to R1 */
    Dlist *temp1 = *headR1;
    Dlist *temp2 = *headR3;

    while(temp2 != NULL)
    {
        dl_insert_last(headR1, tailR1, temp2->data);
        temp2 = temp2->next;
    }
}