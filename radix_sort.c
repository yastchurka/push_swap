#include "push_swap.h"

static int	countBits(struct node **stack) 
{
	struct node		*temp;
	int			count;
	int			bit_counter;

	temp = *stack;
	count = (*stack)->index; //i
	bit_counter = 0;
	while (temp)
	{
		if (temp->index > count) //i
			count = temp->index; //i
		temp = temp->next;
	}
	while ((count >> bit_counter) != 0) 
		bit_counter++; 
	return (bit_counter);
}

void	radix_sort(struct node **stack_a, struct node **stack_b)
{
	struct node	*head;
	int			max_bits;
	int			size;
	int			i;
	int 		j;

	i = 0;
	max_bits = countBits(stack_a);
	size = len(stack_a);
	head = *stack_a;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			head = *stack_a;
			if (((head->index >> i) & 1 ) == 1) //i
				rotate(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (len(stack_b) != 0)
			pa(stack_a, stack_b); 
		i++;
	} 
}
