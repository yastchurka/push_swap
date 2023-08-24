#include "push_swap.h"

int	bad_syntax(char *a)
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

int	check_for_duplicates(struct node **stack, int nb)
{
	struct node	*t;

	t = *stack;
	while (t)
	{
		if (t->value == nb)
			return (1);
		t = t->next;
	}
	return (0);
}

/* int	check_for_overflows(char argv[])
{
	long long	nb;

	nb = small_atoi(argv);
	if (nb >= -2147483648 && nb <= 2147483647)
		return (0);
	return (1);
} */

void	error(struct node **stack)
{
	write(2, "Error\n", 6);
	free_stack(stack);
	exit(1);
}