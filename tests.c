#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int        value;
	struct    node *next;
	struct    node *prev;
} node_t;

int    small_atoi(char *string)
{
	int    nb;
	int i;

	nb = 0;
	i = 0;
	if (!string)
		return (0);
	while (string[i] != '\0')
	{
		nb = nb * 10 + (string[i] - '0');
		i++;
	}
	return (nb);
}

t_stack_node	*find_last_node(t_stack_node *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	append_node(node_t **stack, int nb)
{
	node_t	*node;

	node = malloc(sizeof(node_t));
	if (node == NULL)
		return ;
	if (stack == NULL)
		return ;
	node->next = NULL;
	node->value = nb;
	if (*stack == NULL)
	{
		(*stack) = node;
		node->prev = NULL;
	}
	else
	{
		
	}
}

void	initiate_stack(node_t **stack, char *v[])
{
	int	i, nb = 0;
	while(v[i])
	{
		nb = small_atoi(v[i]);
		append_node(*stack, v[i]);
		i++;
	}
}

int    main(void)
{
	struct node	*a;
	struct node	*b;
	
	a = NULL;
	b = NULL;
	char *v[5] = { v[0] = "\0", v[1] = "1", v[2] = "2", v[3] = "3", v[4] = NULL };
	initiate_stack(&a, v + 1);
	while(a)
	{
		printf("%d", a->value);
		a = a->next;
	} 
	return (0);
}