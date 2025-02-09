#include "apc.h"

int main(int argc, char *argv[])
{
	/* Declare the pointers */
	Dlist *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;
	char operator= * argv[2];
	char *operand1 = argv[1];
	char *operand2 = argv[3];
	int flagOper1 = 0, flagOper2 = 0, swap = 0;
	int result;

	if(argc < 4) // Check for valid argument count
	{
		printf("Enter Valid Number of Arguments\n");
		return FAILURE;
	}
	/* function for validating the input arguments and extracting the operator*/
	
	if(read_validate(&head1, &tail1, &head2, &tail2, &operator, operand1, operand2, &flagOper1, &flagOper2, &swap) == FAILURE)
	{
		return FAILURE;
	}
	

	switch (operator)
	{
	case '+':
		/* call the function to perform the addition operation */
		addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
		if(swap == 0 || swap == 1 || swap == -1)
		{
			if(flagOper1 == 0) // If flag is 0 that means number is positive
			{	
				print_list(headR);
			}
			else if(flagOper1 == 1) // If flag is 1 that means number is negative
			{
				printf("-");
				print_list(headR);
			}
		}

		
		break;
	case '-':
		/* call the function to perform the subtraction operation */
		if(swap == 0) // If swap 0 that means first operand is greater than 2nd operand
		{
			subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
			if(flagOper2 == 0) // If flag is 0 that means number is positive
			{	
				print_list(headR);
			}
			else if(flagOper2 == 1) // If flag is 1 that means number is negative
			{
				printf("-");
				print_list(headR);
			}
		}
		if(swap == 1) // If swap 1 that means second operand is greater than first operand
		{
			subtraction(&head2, &tail2, &head1, &tail1, &headR, &tailR);
			if(flagOper2 == 0) // If flag is 0 that means number is positive
			{	
				print_list(headR);
			}
			else if(flagOper2 == 1) // If flag is 1 that means number is negative
			{
				printf("-");
				print_list(headR);
			}
		}

		if(swap == - 1) // If swap is -1 that means both the operands are same
		{
			printf("0\n");
		}
		
		break;
	case 'x':
		/* call the function to perform the multiplication operation */
		multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
		if(flagOper1 == 0) // If flag is 0 that means number is positive
			print_list(headR);
		else if(flagOper1 == 1) // If flag is 1 that means number is negative
		{
			printf("-");
			print_list(headR);
		}
		break;
	case '/':
		/* call the function to perform the division operation */
		result  = division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
		if(flagOper2 == 0) // If flag is 0 that means number is positive
			printf("%d\n", result);
		else if(flagOper2 == 1) // If flag is 1 that means number is negative
		{
			printf("%d\n", result);
		}
		break;
	default:
		printf("Invalid Input:-( Try again...\n");
	}

	return 0;
}

