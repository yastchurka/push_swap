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

void	free_stack(struct node **stack)
{
	struct node	*a;
	struct node	*temp;

	if (*stack == NULL)
		return ;
	a = *stack;
	while (a)
	{
		temp = a->next;
		free(a);
		a = temp;
	}
	*stack = NULL;
}

/* void	free_input(char **argv)
{
	int	i;

	i = 0;
	while(argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
} */