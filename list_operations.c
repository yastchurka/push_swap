#include <stdio.h>
#include <stdlib.h>

struct node { //change name to sth else
	int data;
	struct node *link;
};

void	add_at_the_end(struct node *head, int data)
{
	struct node *ptr;
	struct node *temp;

	ptr = head;
	temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->link = NULL;
	while (ptr->link != NULL)
		ptr = ptr->link;
	ptr->link = temp;
}

/* sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements */
void	sa(struct node *head)
{
	int	temp_value;
	int	temp_value2;
	
	if (!head || !head->link)
		return ; // ERROR message, declare in .h
	temp_value = head->data;
	temp_value2 = head->link->data;
	head->data = temp_value2;
	head->link->data = temp_value;
}

/* pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty. */
void	pb(struct node *head_of_stack1, struct node *head_of_stack2)
{
	int	temp_value;
	struct node *ptr;
	
	if (!head_of_stack1 || !head_of_stack1->link || !head_of_stack2)
		return ; // ERROR message, declare in .h
	temp_value = head_of_stack1->data;
	head_of_stack2->data = temp_value;
	ptr = head_of_stack1;
	head_of_stack1->link = head_of_stack1->link->link;
	free(ptr);
	ptr = NULL;
}