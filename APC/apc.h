#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define SUCCESS 0;
#define FAILURE -1;
#define LIST_EMPTY -2;
typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}Dlist;

int read_validate(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *operator, char *operand1, char *operand2, int *flagOper1, int *flagOper2, int *swap);
int dl_insert_first(Dlist **head, Dlist **tail, int data);
int dl_insert_last(Dlist **head, Dlist **tail, int data);
int dl_delete_first(Dlist **head, Dlist **tail);
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int dl_delete_list(Dlist **head, Dlist **tail);
int copy_list(Dlist **headR1, Dlist **tailR1, Dlist **headR3, Dlist **tailR3);
int compare_lists(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2);
void print_list(Dlist *head);
#endif

