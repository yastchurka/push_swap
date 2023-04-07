#include <stdio.h>
#include <stdlib.h>

struct node { //change name to sth else
	int			data;
	int			index;
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

void	sb(struct node *head)
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

void	ss(struct node *head1, struct node *head2)
{
	sa(head1);
	sb(head2);
}

int	pb(struct node **head_of_stack1, struct node **head_of_stack2)
{	
	int	x;
	
	if (!head_of_stack1)
		return (-1);
	x = pop(head_of_stack1);
	add_at_the_top(head_of_stack2, x);
}

int	pa(struct node **head_of_stack1, struct node **head_of_stack2)
{	
	int	x;

	if (!head_of_stack2)
		return (-1);
	x = pop(head_of_stack2);
	add_at_the_top(head_of_stack1, x);
}

void	ra(struct node **head) 
{
	struct node *temp;
	
	temp = *head;
	if (*head == NULL || (*head)->link == NULL)
        return ;
    while (temp->link != NULL)
        temp = temp->link;
    temp->link = *head;
    *head = (*head)->link;
    temp->link->link = NULL;
}

void	rb(struct node **head) 
{
	struct node *temp;
	
	temp = *head;
	if (*head == NULL || (*head)->link == NULL)
		return ;
	while (temp->link != NULL)
		temp = temp->link;
	temp->link = *head;
	*head = (*head)->link;
	temp->link->link = NULL;
}

int	rra(struct node **head) 
{
	int	x;

	if (!head)
		return (-1);
	x = pop(head);
	add_at_the_bottom(head, x);
}

int	rrb(struct node **head) 
{
	int	x;

	if (!head)
		return (-1);
	x = pop(head);
	add_at_the_bottom(head, x);
}

void	rr(struct node *head1, struct node *head2)
{
	rb(&head1);
	ra(&head2);
}

void	rrr(struct node *head1, struct node *head2)
{
	rra(&head1);
	rrb(&head2);
}

/* TO DOs:
------ DONE sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
------ DONE ss : sa and sb at the same time.
------ DONE rr : ra and rb at the same time.
------ DONE rrr : rra and rrb at the same time.
------ DONE Negative numbers
Reduce redundant code above
Create the makefile
?Create testing script
Add error message (followed by a \n)
Ogarnij radix sort
Implement radix sort

 */