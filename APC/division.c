#include "apc.h"

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *com1 = *tail1;
    Dlist *com2 = *tail2;
    int c1 = 0, c2 = 0;
    int count = 0;
    /* Count the number of digits in each number */
    while(com1 != NULL)
    {
        c1++;
        com1 = com1->prev;
    }

    while(com2 != NULL)
    {
        c2++;
        com2 = com2->prev;
    }
    /* Insert 0's at first to match the number of digit count in the linked list*/
    if(c1 < c2)
    {
        count = 0;
        return count;
    }
    else if(c2 < c1)
    {
        while((c1 - c2) != 0)
        {
            dl_insert_first(head2, tail2, 0);
            c2++;
        }
    }
    /* If count is same then compare numbers */
    else if(c2 == c1)
    {
        com1 = *head1;
        com2 = *head2;
        while(com1 != NULL && com2 != NULL)
        {
            if(com1->data > com2->data)
            {
                break;
            }
            else if(com2->data > com1->data)
            {
                count = 0;
                return count;
            }
            else
            {
                com1 = com1->next;
                com2 = com2->next;
            }
        }
        count = 1;
        return count;
    }


    count = 0;
    Dlist *temp1 = *head1;
    Dlist *temp2 = *tail1;

    while(compare_lists(*head1, *tail1, *head2, *tail2) >= 0)
    {
        subtraction(head1, tail1, head2, tail2, headR, tailR); /* Call substraction function inside a loop and pass
        operand 1 and operand 2 as argument*/
        //print_list(*head1);
        dl_delete_list(head1, tail1); /* Delete the list containing operand 1 and replace it with the result of 
        substraction operation */
        copy_list(head1, tail1, headR, tailR);
        dl_delete_list(headR, tailR); // Delete the result list for storing the resultant value for next digit in list
        temp1 = *head1; // Update the pointers
        temp2 = *tail1;
        count++; // Increment the count based on number of times substraction operation is called
    }
    return count; // return count

}
/* Function for comparing operand 1 and operand 2 */
int compare_lists(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2)
{
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data > head2->data)
        {
            return 1;
        }    
        else if(head1->data < head2->data)
        {
            return -1;
        }    
        head1 = head1->next;
        head2 = head2->next;
    }
    
    if (head1 == NULL && head2 == NULL)
    {
        return 0;
    }
    else if (head1 != NULL)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}