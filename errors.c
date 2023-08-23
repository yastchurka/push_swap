#include "push_swap.h"

int bad_syntax(char *a)
{
	if (!((*a >= '0' && *a <= '9') || *a == '-' || *a == '+'))
		return (1);
	while (*++a)
	{
		if (!(*a >= '0' && *a <= '9'))
			return (1);
	}
	return (0);
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

void	free_input(char **argv)
{
	int	i;

	i = 0;
	while(argv[i])
	{
		//free(argv[i]);
		i++;
	}
	//free(argv);
}

void	error(struct node **stack, char **argv)
{
	free_stack(stack);
	free_input(argv);
	write(2, "Error\n", 6);
	exit(1);
}