#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    Dlist *headR1 = NULL, *tailR1 = NULL, *headR2 = NULL, *tailR2 = NULL, *headR3 = NULL, *tailR3 = NULL;
    int carry = 0;
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
		dl_insert_first(&headR1, &tailR1, result);
        temp1 = temp1->prev;
	}
	if(carry != 0)
	{
		dl_insert_first(&headR1, &tailR1, carry);
		carry = 0;
	}

    int count = 1;
    temp2 = temp2->prev;
    while(temp2 != NULL)
    {
        int i = 0;
        temp1 = *tail1;
        while( i != count)
        {
            dl_insert_first(&headR2, &tailR2, 0);
            i++;
        }

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
		    dl_insert_first(&headR2, &tailR2, result);
            temp1 = temp1->prev;
        }
	
		if(carry != 0)
	    {
		    dl_insert_first(&headR2, &tailR2, carry);
		    carry = 0;
	    }
        addition(&headR1, &tailR1, &headR2, &tailR2, &headR3, &tailR3);
        dl_delete_list(&headR1, &tailR1);
        dl_delete_list(&headR2, &tailR2);
        copy_list(&headR1, &tailR1, &headR3, &tailR3);
        dl_delete_list(&headR3, &tailR3);
        count++;
        temp2 = temp2->prev;
    }
    copy_list(headR, tailR, &headR1, &tailR1);
}

