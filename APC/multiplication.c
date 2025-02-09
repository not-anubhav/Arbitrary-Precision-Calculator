#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    Dlist *headR1 = NULL, *tailR1 = NULL, *headR2 = NULL, *tailR2 = NULL, *headR3 = NULL, *tailR3 = NULL;
    int carry = 0;
	/* Multiplying last digit of operand 2 with all the digits of operand to get first result */
    while(temp1 != NULL)
    {
        int result = temp1->data * temp2->data;
		if(result > 9)
		{
			if(carry == 0)
			{
				carry = result / 10;
				result = result % 10;
			}
			else
			{
				result = (result + carry);
				carry = result / 10;
				result = result % 10;
			}
		}
		else
		{
			result = result + carry;
			if(result > 9)
			{
				carry = result / 10;
				result = result % 10;
			}
			else
			{
				carry = 0;
			}
		}
		dl_insert_first(&headR1, &tailR1, result); // Insert the result in linked list using insert first function
        temp1 = temp1->prev;
	}
	if(carry != 0) // If for the last place carry is not 0
	{
		dl_insert_first(&headR1, &tailR1, carry); // Insert carry also inside the list
		carry = 0; // Reset the carry
	}

    int count = 1;
    temp2 = temp2->prev; // Move the 2nd operand pointer to second place and traverse it till last place digit
    while(temp2 != NULL)
    {
        int i = 0;
        temp1 = *tail1;
        while( i != count)
        {
            dl_insert_first(&headR2, &tailR2, 0);
            i++;
        }
		/* loop for multiplying each digit of operand 2 with each digit of operand 1 */
        while(temp1 != NULL)
        {
            int result = temp1->data * temp2->data;
		    if(result > 9)
		    {
			    if(carry == 0)
			    {
				    carry = result / 10;
				    result = result % 10;
			    }
			    else
			    {
				    result = (result + carry);
				    carry = result / 10;
				    result = result % 10;
			    }
		    }
		    else
		    {
			    result = result + carry;
			    if(result > 9)
			    {
				    carry = result / 10;
				    result = result % 10;
			    }
			    else
			    {
				    carry = 0;
			    }
		    }
		    dl_insert_first(&headR2, &tailR2, result); // Insert the result in linked list using insert first function
            temp1 = temp1->prev;
        }
	
		if(carry != 0) // If for the last place carry is not 0
	    {
		    dl_insert_first(&headR2, &tailR2, carry); // Insert carry also inside the list
		    carry = 0; // reset the carry
	    }
        addition(&headR1, &tailR1, &headR2, &tailR2, &headR3, &tailR3); // Add 1st and 2nd result and store it in 3rd linked list
        dl_delete_list(&headR1, &tailR1); // Delete the 1st result list
        dl_delete_list(&headR2, &tailR2); // Delete the 2nd result list
        copy_list(&headR1, &tailR1, &headR3, &tailR3); // Copy the addition result in list 1
        dl_delete_list(&headR3, &tailR3); // delete the 3rd list also
        count++; // Increment the count
        temp2 = temp2->prev; //traverse
    }
	
    copy_list(headR, tailR, &headR1, &tailR1); // Finally copy the result in list 1 to final result list
	/* Remove extra 0's added from the list*/
	Dlist *temp = *headR;
	int count1 = 0;
	while (temp->next != NULL)
	{
		if(temp->data > 0)
		{
			break;
		}
		count1++;
		temp = temp->next;
	}
	
	while(count1)
	{
		dl_delete_first(headR, tailR);
		count1--;
	}
}

