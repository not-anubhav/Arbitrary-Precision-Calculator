#include "apc.h"

int read_validate(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *operator, char *operand1, char *operand2, int *flagOper1, int *flagOper2, int *swap)
{
    /* Code for reading the inputs */
	int i = 0, j = 0, cond = 0;
	if(!isdigit(operand1[0]) && !isdigit(operand2[0]))
	{
		i++;
		j++;
		cond = 1;
	}
	else if(!isdigit(operand1[0]) && isdigit(operand2[0]))
	{
		i++;
		cond = 2;
	}
	else if(isdigit(operand1[0]) && !isdigit(operand2[0]))
	{
		j++;
		cond = 3;
	}
	else
	{
		cond = 4;
	}
	int iter1 = i, iter2 = j;
    int count1 = 0, count2 = 0;
	while(operand1[i] != '\0')
	{
		if(isdigit(operand1[i]))
		{
			int n1 = operand1[i] - 48;
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

	 if(count1 < count2)
	{
		*swap = 1;
	}
	else if(count1 == count2)
	{
		Dlist *temp1 = *head1;
		Dlist *temp2 = *head2;
		while(operand1[iter1] != '\0' && operand2[iter2] != '\0')
		{
			if(operand1[iter1] > operand2[iter2])
			{
				*swap = 0;
				break;
			}
			else if(operand1[iter1] < operand2[iter2])
			{
				*swap = 1;
				break;
			}
			else
			{
				*swap = -1;
				iter1++;
				iter2++;
			}
		}
	}

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

    
}