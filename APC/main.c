#include "apc.h"

int main(int argc, char *argv[])
{
	printf("\n%s %s %s\n", argv[1],argv[2], argv[3]);
	/* Declare the pointers */
	Dlist *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;
	char operator= * argv[2];
	char *operand1 = argv[1];
	char *operand2 = argv[3];
	int flagOper1 = 0, flagOper2 = 0, swap = 0;

	if(argc < 4)
	{
		printf("Enter Valid Number of Arguments\n");
		return FAILURE;
	}
	
	read_validate(&head1, &tail1, &head2, &tail2, &operator, operand1, operand2, &flagOper1, &flagOper2, &swap);
	/* Function for extracting the operator */

	switch (operator)
	{
	case '+':
		/* call the function to perform the addition operation */
		addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
		if(swap == 0 || swap == 1 || swap == -1)
		{
			if(flagOper1 == 0)
			{	
				print_list(headR);
			}
			else if(flagOper1 == 1)
			{
				printf("-");
				print_list(headR);
			}
		}

		
		break;
	case '-':
		/* call the function to perform the subtraction operation */
		if(swap == 0)
		{
			subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
			if(flagOper2 == 0)
			{	
				print_list(headR);
			}
			else if(flagOper2 == 1)
			{
				printf("-");
				print_list(headR);
			}
		}
		if(swap == 1)
		{
			subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
			if(flagOper2 == 0)
			{	
				print_list(headR);
			}
			else if(flagOper2 == 1)
			{
				printf("-");
				print_list(headR);
			}
		}

		if(swap == - 1)
		{
			printf("0\n");
		}
		
		break;
	case 'x':
		/* call the function to perform the multiplication operation */
		multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
		if(flagOper1 == 0)
			print_list(headR);
		else if(flagOper1 == 1)
		{
			printf("-");
			print_list(headR);
		}
		break;
	case '/':
		/* call the function to perform the division operation */
		int result  = division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
		if(flagOper2 == 0)
			printf("Result : %d\n", result);
		else if(flagOper2 == 1)
		{
			printf("Result : -%d\n", result);
		}
		break;
	default:
		printf("Invalid Input:-( Try again...\n");
	}

	return 0;
}

