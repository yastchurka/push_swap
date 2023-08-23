#include "push_swap.h"

void	rotate(struct node **stack)
{
	struct node	*temp;

	//possible better error handling
	if (NULL == *stack)
		return ;
	temp = find_last_node(*stack);
	temp->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next->prev = temp;
	temp->next->next = NULL;
	write(1, "ra\n", 3);
}

void	rotate_down(struct node **stack)
{
	struct node	*last;

	//possible better error handling
	if (NULL == *stack)
		return ;
	last = find_last_node(*stack);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	write(1, "rra\n", 4);
} 