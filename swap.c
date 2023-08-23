#include "push_swap.h"

void	swap(struct node **stack)
{
	struct node *t;

	if (NULL == *stack)
		return ;
	if (!((*stack)->next))
		return ;
	t = (*stack)->next;
	t->prev = NULL;
	(*stack)->prev = t;
	if (!((*stack)->next->next))
	{
		(*stack)->next = NULL;
		t->next = (*stack);
	}
	else
		(*stack)->next = t->next;
	t->next->prev = *stack;
	t->next = *stack;
	(*stack) = t;
	write(1, "sa\n", 3);
}