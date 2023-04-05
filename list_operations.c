#include <stdio.h>
#include <stdlib.h>

struct node { //change name to sth else
	int data;
	struct node *link;
};

void	add_at_the_bottom(struct node **head, int data)
{
	struct node *ptr;
	struct node *temp;

	ptr = *head;
	temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->link = NULL;
	while (ptr->link != NULL)
		ptr = ptr->link;
	ptr->link = temp;
}

void	add_at_the_top(struct node **head, int data) 
{
    struct node *new_node; 
	
	new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->link = *head;
    *head = new_node;
}

//deletes the top element of the stack and returnes it
int pop(struct node **head_of_stack)
{
	struct	node *temp;
	int		x;
	
	x = 0;
	if (!(*head_of_stack))
		return (-1); //change error message
	else
	{
		temp = *head_of_stack;
		x = (*head_of_stack)->data;
		*head_of_stack = (*head_of_stack)->link;
		//free(temp); 
		temp = NULL;
	}
	return (x);
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
int	pb(struct node **head_of_stack1, struct node **head_of_stack2)
{
	int x = pop(head_of_stack1);
	add_at_the_top(head_of_stack2, x);
}