#include "apc.h"
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
    int Borrow = 0;

	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;
    int count1 = 0, count2 = 0; 
	/* Count the number of digits in both operands */
    while(temp1 != NULL)
	{
		count1++;
		temp1 = temp1->prev;
	}
	while(temp2 != NULL)
	{
		count2++;
		temp2 = temp2->prev;
	}
	/* Insert zeros at first */
	if(count2 < count1)
	{
		while((count1 - count2) != 0)
		{
			dl_insert_first(head2, tail2, 0);
			count2++;
		}
	}
	else if(count1 < count2)
	{
		while(count2 - count1 != 0)
		{
			dl_insert_first(head1, tail1, 0);
			count1++;
		}
	}

	temp1 = *tail1;
	temp2 = *tail2;
	/* Calculation  */
    while(temp1 != NULL || temp2 != NULL)
    {
        int result;
        result = (temp1->data - Borrow) - temp2->data; // Calculate the result for each node from tail side
        if(result < 0) // If result is less than 0
        {
            result = result + 10; // Add 10 in the result
            Borrow = 1; // Update the borrow as 1
        }
        else
        {
            Borrow = 0; // If result is greater equal to 0, update the Borrow as 0
        }
        dl_insert_first(headR, tailR, result); // Insert the result at first
        temp1 = temp1->prev;
        temp2 = temp2->prev;
    }
	/* For removing Zeros previously added from first */
	Dlist *temp = *headR;
	int count = 0;
	while (temp->next != NULL)
	{
		if(temp->data > 0)
		{
			break;
		}
		count++;
		temp = temp->next;
	}
	
	while(count)
	{
		dl_delete_first(headR, tailR);
		count--;
	}
}