#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int			value;
	struct node	*next;
	struct node	*prev;
} nodek_t;

int	small_atoi(char *str)
{
	int neg;
	int num;
	int i;

	i = 0;
	neg = 1;
	num = 0;
 	while (str[i] <= ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			neg *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
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

void    initiate_stack(struct node **a, char *argv[])
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	//if (nbr > INT_MAX || nbr < INT_MIN)
	//if (error_repetition(*a, (int)nbr))
	while (argv[i])
	{
		nb = small_atoi(argv[i]);
		append_node(a, nb);
		i++;
	}
}

static void	push(struct node **stack_a, struct node **stack_b)
{
	struct node	*temp;

	if (NULL == *stack_a)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	temp->prev = NULL;
	if (NULL == *stack_b)
	{
		*stack_b = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *stack_b;
		temp->next->prev = temp;
		*stack_b = temp;
	}
}

void	pa(struct node **a, struct node **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(struct node **a, struct node **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}

void	rotate(struct node **stack)
{
	struct node	*temp;

	//possible better error handling
	if (NULL == *stack)
		return ;
	temp = find_last_node(*stack);
	temp->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next->prev = temp;
	temp->next->next = NULL;
	write(1, "ra\n", 3);
}

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

static int	countBits(struct node **stack) 
{
	struct node		*temp;
	int			count;
	int			bit_counter;

	temp = *stack;
	count = (*stack)->value;
	bit_counter = 0;
	while (temp)
	{
		if (temp->value > count)
			count = temp->value;
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
			if (((head->value >> i) & 1 ) == 1)
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

int	is_sorted(struct node **stack_a)
{
	struct node	*temp;

	temp = *stack_a;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	sorting(struct node **stack_a, struct node **stack_b, int argc)
{
	if (argc == 2)
		rotate(stack_a);
	if (argc == 3)
		sort_3(stack_a, stack_b);
	if (argc == 3)
		sort_4(stack_a, stack_b);
	if (argc == 3)
		sort_5(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	struct node	*a;
	struct node *b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argc[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	initiate_stack(&a, argv + 1);
	if (is_sorted(&a) == 0)
	{
		sorting(&a, &b, argc);
		return (0);
	}
	//free_a
	
	
	
	printf("A:\n");
	printf("------\n");
 	while(a)
	{
		printf("%d\n", a->value);
		a = a->next;
	}
	printf("\n");
	printf("B:\n");
	printf("------\n");
	while(b)
	{
		printf("%d\n", b->value);
		b = b->next;
	}
	return (0);
}