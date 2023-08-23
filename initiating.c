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
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (argv[i])
	{
		if (bad_syntax(argv[i]) == 1)
		{
			printf("The winner is: %c", *argv[i]);
			error(a, argv);
		}
		nb = small_atoi(argv[i]);
		/* if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv);
		if (error_repetition(*a, (int)nbr))
			error_free(a, argv);  */
		append_node(a, nb);
		i++;
	}
}