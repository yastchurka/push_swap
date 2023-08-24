#include "push_swap.h"

void    append_node(struct node **stack, int nbr)
{
	struct node *node;
	struct node *last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(struct node));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->value = nbr;
	node->index = -1;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	initiate_stack(struct node **a, char *argv[])
{
	int			i;
	long long	nb;

	i = 0;
	nb = 0;
	while (argv[i])
	{
		if (bad_syntax(argv[i]) == 1)
			error(a);
		nb = small_atoi(argv[i]);
 		if (nb < -2147483648 || nb > 2147483647)
			error(a);
		if (check_for_duplicates(a, nb) == 1)
			error(a);
		append_node(a, nb);
		i++;
	}
}