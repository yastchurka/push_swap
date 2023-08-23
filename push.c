#include "push_swap.h"

void	push(struct node **stack_a, struct node **stack_b)
{
	struct node	*temp;

	if (NULL == *stack_a)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	temp->prev = NULL;
	if (NULL == *stack_b)
	{
		*stack_b = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *stack_b;
		temp->next->prev = temp;
		*stack_b = temp;
	}
}

void	pa(struct node **a, struct node **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(struct node **a, struct node **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}