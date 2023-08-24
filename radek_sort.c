#include "push_swap.h"

int	get_distance(struct node **stack_a, struct node *next_min)
{
	struct node *temp;
	int         min_index;
	int         distance;

	temp = *stack_a;
	min_index = next_min->index;
	distance = 0;
	while (temp)
	{
		if (temp->index == min_index)
			return (distance);
		temp = temp->next;
		distance++;
	}
	return (distance);
}

void	radek_sorting(struct node **stack_a, struct node **stack_b, int distance, int round)
{
	if (distance == 0)
		pb(stack_a, stack_b);
	if (distance == 1)
	{
		swap(stack_a);
		pb(stack_a, stack_b);
	}
	if (distance == 2)
	{
		rotate(stack_a);
		rotate(stack_a);
		pb(stack_a, stack_b);
	}
	if (distance == 3 && round == 0)
	{
		rotate_down(stack_a);
		rotate_down(stack_a);
		pb(stack_a, stack_b);
	}
	if ((distance == 3 && round == 1) || distance == 4)
	{
		rotate_down(stack_a);
		pb(stack_a, stack_b);
	}
}

struct node	*get_next_rad(struct node **stack_a)
{
	struct node	*temp;
	struct node	*ptr;

	temp = *stack_a;
	ptr = temp;
	while (temp)
	{
		if (temp->value < ptr->value)
			ptr = temp;
		temp = temp->next;
	}
	return (ptr);
}

void	radek_sort(struct node **stack_a, struct node **stack_b)
{
	struct node *next_min;
	int         distance;
	int         i;

	i = 0;
	while (i < 2)
	{
		next_min = get_next_rad(stack_a);
		distance = get_distance(stack_a, next_min);
		radek_sorting(stack_a, stack_b, distance, i);
		i++;
	}
	sort3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
