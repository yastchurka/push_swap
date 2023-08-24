#include "push_swap.h"

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
	index_all(stack_a);
	if (argc == 2)
		rotate(stack_a);
	else if (argc == 3)
		sort3(stack_a);
	else if (argc == 5)
		radek_sort(stack_a, stack_b); 
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
	
	////////////////////////////////////// no comments ////////////////////////////////////////////
/*   	printf("A:\n");
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
	}   */
	//////////////////////////////////////////////////////////////////////////////////////////////

	break_me_free(&a);
	break_me_free(&b);
	return (0);
}
