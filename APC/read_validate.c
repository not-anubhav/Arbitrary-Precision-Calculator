#include "apc.h"

int read_validate(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *operator, char *operand1, char *operand2, int *flagOper1, int *flagOper2, int *swap)
{
    /* Validate signs present before number */
	int i = 0, j = 0, cond = 0;
	if(!isdigit(operand1[0]) && !isdigit(operand2[0]))
	{
		if((operand1[0] == '+' || operand1[0] == '-' || operand1[0] == 'x' || operand1[0] == '/') 
		&& (operand2[0] == '+' || operand2[0] == '-' || operand2[0] == 'x' || operand2[0] == '/'))
		{
			i++;
			j++;
			cond = 1;
		}
		else
		{
			return FAILURE;
		}
	}
	else if(!isdigit(operand1[0]) && isdigit(operand2[0]))
	{
		if((operand1[0] == '+' || operand1[0] == '-' || operand1[0] == 'x' || operand1[0] == '/'))
		{
			i++;
			cond = 2;
		}
		else
		{
			return FAILURE;
		}
	}
	else if(isdigit(operand1[0]) && !isdigit(operand2[0]))
	{
		if((operand2[0] == '+' || operand2[0] == '-' || operand2[0] == 'x' || operand2[0] == '/'))
		{
			j++;
			cond = 3;
		}
		else
		{
			return FAILURE;
		}
	}
	else if(isdigit(operand1[0]) && isdigit(operand2[0]))
	{
		cond = 4;
	}
	else
	{
		return FAILURE;
	}
	int iter1 = i, iter2 = j;
    int count1 = 0, count2 = 0; // Count for counting number of digits present in number
	/* Code for reading the inputs */
	while(operand1[i] != '\0')
	{
		if(isdigit(operand1[i]))
		{
			int n1 = operand1[i] - 48; // convert character to integer
			dl_insert_last(head1, tail1, n1);
			i++;
            count1++;
		}
		else
		{
			return FAILURE;
		}
	}
	while(operand2[j] != '\0')
	{
		if(isdigit(operand2[j]))
		{
			int n2 = operand2[j] - 48;
			dl_insert_last(head2, tail2, n2);
			j++;
            count2++;
		}
		else
		{
			return FAILURE;
		}
	}

	 if(count1 < count2) // If first number is less than 2nd number i.e we have to swap the numbers
	{
		*swap = 1;
	}
	else if(count1 == count2) // if both have same number of digits
	{
		Dlist *temp1 = *head1;
		Dlist *temp2 = *head2;
		/*Compare the digits of both numbers to find out with one is greater and which one is smaller */
		while(operand1[iter1] != '\0' && operand2[iter2] != '\0')
		{
			if(operand1[iter1] > operand2[iter2]) // If first is greater no need to swap
			{
				*swap = 0;
				break;
			}
			else if(operand1[iter1] < operand2[iter2]) // if second number is greater that means we have to swap
			{
				*swap = 1;
				break;
			}
			else // Both numbers are same
			{
				*swap = -1;
				iter1++;
				iter2++;
			}
		}
	}
	/* Validation for Addition */
	if(*operator == '+')
	{
        if(cond == 3)
        {
            if(operand2[0] == '+')
            {
                *operator = '+';
                *flagOper1 = 0;
            }
            else if(operand2[0] == '-')
            {
                *operator = '-';
                if(*swap == 0)
				{
					*flagOper2 = 0;
				}
				else if(*swap == 1)
				{
					*flagOper2 = 1;
				}
				else if(*swap == -1)
				{
					*flagOper2 = 0;
				}
            }
        }
        else if(cond == 2)
        {
            if(operand1[0] == '+')
            {
                *operator = '+';
                *flagOper1 = 0;
            }
            else if(operand1[0] == '-')
            {
                *operator = '-';
                if(*swap == 0)
				{
					*flagOper2 = 1;
				}
				else if(*swap == 1)
				{
					*flagOper2 = 0;
				}
				else if(*swap == -1)
				{
					*flagOper2 = 0;
				}
            }
        }
		else if((operand1[0] == '+' && operand2[0] == '+') || (operand1[0] == '-' && operand2[0] == '-'))
		{
			*operator = '+';
			
			if(operand1[0] == '-' && operand2[0] == '-')
			{
				*flagOper1 = 1;
			}
			else
			{
				*flagOper1 = 0;
			}
		}
		else if((operand1[0] == '+' && operand2[0] == '-') || (operand1[0] == '-' && operand2[0] == '+'))
		{
			*operator = '-';
		
			if(operand1[0] == '+' && operand2[0] == '-')
			{
				if(*swap == 0)
				{
					*flagOper2 = 0;
				}
				else if(*swap == 1)
				{
					*flagOper2 = 1;
				}
			}
			else
			{
				if(*swap == 0)
				{
					*flagOper2 = 1;
				}
				else if(*swap == 1)
				{
					*flagOper2 = 0;
				}
			}
		}
		else if(cond == 4)
		{
			*operator = '+';
			*swap = 0;
			*flagOper1 = 0;
		}
	}

	/* Validation for substraction */
	else if(*operator == '-')
	{
        if(cond == 3)
        {
            if(operand2[0] == '+')
            {
                *operator = '-';
				if(*swap == 0)
				{
					*flagOper2 = 0;
				}
				else if(*swap == 1)
				{
					*flagOper2 = 1;
				}
            }
            else if(operand2[0] == '-')
            {
                *operator = '+';
				*flagOper1 = 0;
            }
        }
        else if(cond == 2)
        {
            if(operand1[0] == '+')
            {
                *operator = '-';
                if(*swap == 1)
				{
					*flagOper2 = 1;
				}
				else if(*swap == 0)
				{
					*flagOper2 = 0;
				}
            }
            else if(operand1[0] == '-')
            {
                *operator = '+';
                *flagOper1 = 1;
            }
        }
		else if((operand1[0] == '+' && operand2[0] == '+') || (operand1[0] == '-' && operand2[0] == '-'))
		{
			*operator = '-';
			if(operand1[0] == '+' && operand2[0] == '+')
			{
				if(*swap == 0)
				{
					*flagOper2 = 0;	
				}
				else if(*swap == 1)
				{
					*flagOper2 = 1;
				}
			}
			else if(operand1[0] == '-' && operand2[0] == '-')
			{
				if(*swap == 0)
				{
					*flagOper2 = 1;
				}
				else if(*swap == 1)
				{
					*flagOper2 = 0;
				}
			}
			
		}
		else if((operand1[0] == '+' && operand2[0] == '-') || (operand1[0] == '-' && operand2[0] == '+'))
		{
			*operator = '+';
			if(operand1[0] == '+' && operand2[0] == '-')
			{
				if(*swap == 0)
				{
					*flagOper1 = 0;
				}
				else if(*swap == 1)
				{
					*flagOper1 = 0;
				}
			}
			else if(operand1[0] == '-' && operand2[0] == '+')
			{
				if(*swap == 0)
				{
					*flagOper1 = 1;
				}
				else if(*swap == 1)
				{
					*flagOper1 = 1;
				}
			}
		}
		else if(cond == 4)
		{
			*operator = '-';
			if(*swap == 0)
			{
				*flagOper2 = 0;
			}
			else if(*swap == 1)
			{
				*flagOper2 = 1;
			}
			else if(*swap == -1)
			{
				*flagOper2 = 0;
			}
		}
	}
	/* Validation for multiplication */
	else if(*operator == 'x')
	{
        if(cond == 3)
        {
            if(operand2[0] == '+')
            {
                *flagOper1 = 0;
                
            }
            else if(operand2[0] == '-')
            {
                *flagOper1 = 1;
                
            }
        }
        else if(cond == 2)
        {
            if(operand1[0] == '+')
            {
                *flagOper1 = 0;
                
            }
            else if(operand1[0] == '-')
            {
                *flagOper1 = 1;
                
            }
        }
		else if((operand1[0] == '+' && operand2[0] == '+') || (operand1[0] == '-' && operand2[0] == '-'))
		{
			*flagOper1 = 0;
			
		}
		else if((operand1[0] == '+' && operand2[0] == '-') || (operand1[0] == '-' && operand2[0] == '+'))
		{
			*flagOper1 = 1;
			
		}
	}
	/* Validation for Division */
	else if(*operator == '/')
	{
        if(cond == 3)
        {
            if(operand2[0] == '+')
            {
                *flagOper2 = 0;
                
            }
            else if(operand2[0] == '-')
            {
                *flagOper2 = 1;
               
            }
        }
        else if(cond == 2)
        {
            if(operand1[0] == '+')
            {
                *flagOper2 = 0;
                
            }
            else if(operand1[0] == '-')
            {
                *flagOper2 = 1;
                
            }
        }
		else if((operand1[0] == '+' && operand2[0] == '+') || (operand1[0] == '-' && operand2[0] == '-'))
		{
			*flagOper2 = 0;
			
		}
		else if((operand1[0] == '+' && operand2[0] == '-') || (operand1[0] == '-' && operand2[0] == '+'))
		{
			*flagOper2 = 1;
			
		}
	}
	return SUCCESS;
}