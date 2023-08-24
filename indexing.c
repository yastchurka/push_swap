#include "push_swap.h"

struct node	*get_next_min(struct node **stack_a)
{
	struct node	*temp;
	struct node	*ptr;
	int			flag;

	temp = *stack_a;
	ptr = temp;
	flag = 0;
	while (temp)
	{
		if (temp->index == -1 && (flag == 0 || temp->value < ptr->value))
		{
			ptr = temp;
			flag = 1;
		}
		temp = temp->next;
	}
	return (ptr);
}

void	index_all(struct node **stack_a)
{
	struct node	*temp;
	int			index;
	int			i;

	index = 0;
	temp = *stack_a;
	i = 0;
	while (i < len(stack_a))
	{
		temp = get_next_min(stack_a);
		temp->index = index++;
		i++;
	}
}