#include "apc.h"
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	int carry = 0;

	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;
	int count1 = 0, count2 = 0;
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

	while(temp1 != NULL || temp2 != NULL)
	{
		int result = temp1->data + temp2->data;
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
		dl_insert_first(headR, tailR, result);
		temp1 = temp1->prev;
		temp2 = temp2->prev;
	}
	if(carry != 0)
	{
		dl_insert_first(headR, tailR, carry);
	}
}

