/* 
	check user's arguments;
	create stack b;

*/

#include <stdio.h>
#include <stdlib.h>

struct node { //change name to sth else
	int data;
	struct node *link;
};

void	add_at_the_end(struct node *head, int data);
void	sa(struct node *head);
void	pb(struct node *head_of_stack1, struct node *head_of_stack2);
int ft_atoi(char argv[]);

int	ft_print_content(struct node *head)
{
	struct node *ptr = NULL;
	ptr = head;
	while(ptr != NULL)
	{
		printf("%d\n", ptr->data); //we can't use printf
		ptr = ptr->link;
	}
}

void initiate_new_lists(struct node *head_of_stack1, int argc, char **argv)
{
	int	i;
	if (argc >= 3)
	{
		struct node *head_of_stack2;
		head_of_stack2 = malloc(sizeof(struct node));
	
		head_of_stack2->link = NULL;
		i = 2;
		head_of_stack1->data = ft_atoi(argv[1]);
		head_of_stack1->link = NULL;
		while(argv[i])
		{
			add_at_the_end(head_of_stack1, ft_atoi(argv[i]));
			i++;
		}
		pb(head_of_stack1, head_of_stack2);
		printf("That's the content of stack1: \n");
		//ft_print_content(head_of_stack1); // that's just for us to see the input/output;
		printf("That's the content of stack2: \n");
		ft_print_content(head_of_stack2); 
	}
	else
		printf("%d", ft_atoi(argv[1]));
}

/* We want to add an element of the first list to the stack B */
int	main(int argc, char **argv)
{
	struct node *head_of_stack1;

	head_of_stack1 = malloc(sizeof(struct node));
	initiate_new_lists(head_of_stack1, argc, argv);
    return (0);
}