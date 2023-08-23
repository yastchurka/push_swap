#include "push_swap.h"

void   fuck_the_norm(struct node **stack_a)
{
	rotate_down(stack_a);
	rotate_down(stack_a);
}

void   fuck_the_norm2(struct node **stack_a)
{
	swap(stack_a);
	rotate(stack_a);
}

void    sort3(struct node **stack_a)
{
	struct node *t;

	t = *stack_a;
	if (t->index > t->next->index 
		&& t->next->index < t->next->next->index
			&& t->index > t->next->next->index)
		fuck_the_norm(stack_a);
	else if (t->index < t->next->index 
		&& t->next->index > t->next->next->index
			&& t->index < t->next->next->index)
		fuck_the_norm2(stack_a);
	else if (t->index > t->next->index 
		&& t->next->index > t->next->next->index)
	{
		swap(stack_a);
		rotate_down(stack_a);
	}
    else if (t->index < t->next->index && t->next->index > t->next->next->index)
		rotate_down(stack_a);
    else if (t->index > t->next->index && t->next->index < t->next->next->index)
		swap(stack_a);
}
