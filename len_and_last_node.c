#include "push_swap.h"

int	len(struct node **stack)
{
	struct node	*temp;
	int			i;

	temp = *stack;
	i = 0;
	//fix error handling 
	if (!stack)
		return (0);
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

struct node *find_last_node(struct node *node)
{
	struct node	*temp;

	temp = node;
	if (temp == NULL)
		return (NULL);
	while (temp->next)
		temp = temp->next;
	return(temp);
}