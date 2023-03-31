/* 
	check user's arguments;
	create stack b;

*/

#include <stdio.h>
#include <stdlib.h>

int ft_atoi(char argv[]);

struct node { //change name to sth else
	int data;
	struct node *link;
};

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

int	add_at_the_end(struct node *head, int data)
{
	struct node *ptr;
	struct node *temp;

	ptr = head;
	temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->link = NULL;
	while (ptr->link != NULL)
		ptr = ptr->link;
	ptr->link = temp;
}

void initiate_new_list(struct node *head_of_stack1, int argc, char **argv)
{
	int	i;
	if (argc >= 3)
	{
		i = 2;
		head_of_stack1->data = ft_atoi(argv[1]);
		head_of_stack1->link = NULL;
		while(argv[i])
		{
			add_at_the_end(head_of_stack1, ft_atoi(argv[i]));
			i++;
		}
		ft_print_content(head_of_stack1); // tha's just for us to see the input/output
	}
	else
		printf("%d", ft_atoi(argv[1]));
}

/* We want to add an element of the first list to the stack B */
int	main(int argc, char **argv)
{
	struct node *head_of_stack1;
	struct node *head_of_stack2;

	head_of_stack1 = malloc(sizeof(struct node));
	initiate_new_list(head_of_stack1, argc, argv);
	
    return (0);
}