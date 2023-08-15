# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>

typedef struct node {
	int			value;
	int			index;
	struct node	*next;
	struct node	*prev;
} nodek_t;

/*
 * Args at the command line are
 * spaced separated strings
*/
static int	count_words(char *str, char separator)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == separator)
			++str;
		while (*str != separator && *str)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++str;
		}
	}
	return (count);
}

/*
 * I exploit static variables
 * which are basically 
 * "Global private variables"
 * i can access it only via the get_next_word function
*/
static char	*get_next_word(char *str, char separator)
{
	static int	cursor = 0;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == separator)
		++cursor;
	while ((str[cursor + len] != separator) && str[cursor + len])
		++len;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (NULL == next_str)
		return (NULL);
	while ((str[cursor] != separator) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

/*
 * I recreate an argv in the HEAP
 *
 * +2 because i want to allocate space
 * for the "\0" Placeholder and the final NULL
 *
 * vector_strings-->[p0]-> "\0" Placeholder to mimic argv
 * 				 |->[p1]->"Hello"
 * 				 |->[p2]->"how"
 * 				 |->[p3]->"Are"
 * 				 |->[..]->"..""
 * 				 |->[NULL]
*/
char	**ft_split(char *str, char separator)
{
	int		words_number;
	char	**vector_strings;
	int		i;

	i = 0;
	words_number = count_words(str, separator);
	if (!words_number)
		exit(1);
	vector_strings = malloc(sizeof(char *) * (size_t)(words_number + 2));
	if (NULL == vector_strings)
		return (NULL);
	while (words_number-- >= 0)
	{
		if (0 == i)
		{
			vector_strings[i] = malloc(sizeof(char));
			if (NULL == vector_strings[i])
				return (NULL);
			vector_strings[i++][0] = '\0';
			continue ;
		}
		vector_strings[i++] = get_next_word(str, separator);
	}
	vector_strings[i] = NULL;
	return (vector_strings);
}

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

//SPLIT AND ATOI UPSTAIRS =======================

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

struct node *get_next_min(struct node **stack_a)
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

void   index_all(struct node **stack_a)
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
	index_all(a);
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
	/* if (argc == 3)
		sort_3(stack_a, stack_b);
	if (argc == 3)
		sort_4(stack_a, stack_b);
	if (argc == 3)
		sort_5(stack_a, stack_b); */
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	struct node	*a;
	struct node *b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
	{
		argc = count_words(argv[1], ' ') + 1;
		argv = ft_split(argv[1], ' ');
	}
	initiate_stack(&a, argv + 1);
	if (is_sorted(&a) == 0)
		sorting(&a, &b, argc - 1);
	//free_a
	
	
	
	/* printf("A:\n");
	printf("------\n");
 	while(a)
	{
		printf("Liczba: %d o indexie: %d\n", a->value, a->index);
		a = a->next;
	}
	printf("\n");
	printf("B:\n");
	printf("------\n");
	while(b)
	{
		printf("%d\n", b->value);
		b = b->next;
	} */
	return (0);
}