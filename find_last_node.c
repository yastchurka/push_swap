#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int        value;
	struct    node *next;
	struct    node *prev;
} node_t;

int	small_atoi(char *string)
{
	int    nb;
	int i;

	i = 0;
	if (!string)
		return (0);
	nb = 0;
	while (string[i] != '\0')
	{
		nb = nb * 10 + (string[i] - '0');
		i++;
	}
	return (nb);
}
/* --------------------------------------------------------------------------------------- */

void    initiate_stack(node_t **stack, char *v[])
{
	int    i = 0;
	node_t    *node1;
	node_t    *node2;
	node_t    *node3;
	node_t    *ptr;

	node1 = malloc(sizeof(node_t));
	node2 = malloc(sizeof(node_t));
	node3 = malloc(sizeof(node_t));
	ptr = node1; //?
	node1->value = small_atoi(v[0]);
	node1->prev = NULL;
	node1->next = node2;

	node2->prev = ptr;
	node2->value = small_atoi(v[1]);
	node2->next = node3;

	ptr = node2;
	node3->prev = ptr;
	node3->value = small_atoi(v[2]);
	(*stack) = node1;
}

node_t	*find_last_node(node_t *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}


int    main(void)
{
	struct node    *a;
	struct node    *b;
	struct node    *c;
	struct node    *winner;

	a = NULL;
	b = NULL;
	char *v[5] = { v[0] = "\0", v[1] = "1", v[2] = "2", v[3] = "5" };
	initiate_stack(&a, v + 1);
	c = a;
	while(a)
	{
		printf("NODES: %d", a->value);
		a = a->next;
	}
	winner = find_last_node(c);
	printf("The Last Node award winner is: %d!", winner->value);
	return (0);
}