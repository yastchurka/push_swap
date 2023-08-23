#include "push_swap.h"

void	break_me_free(struct node **stack)
{
	struct node	*temp;
	struct node	*ptr;

	temp = *stack;
	while (temp)
	{
		ptr = temp->next;
		free(temp);
		temp = ptr;
	}
	*stack = NULL;
}