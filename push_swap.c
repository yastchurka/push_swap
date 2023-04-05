#include <stdio.h>
#include <stdlib.h>

struct node { //change name to sth else
	int		data;
	int		index;
	struct	node *link;
};

/* this needs to go to the .h file */
// FUNCTIONS PROTOTYPES
struct	node *gen_new_nodes(int data);
void	add_at_the_bottom(struct node **head, int data);
void	sa(struct node *head);
int		pb(struct node **head_of_stack1, struct node **head_of_stack2);
int 	ft_atoi(char argv[]);
int 	pop(struct node **head_of_stack);

//PRINTING CONTENT, JUST FOR TESTING
int	ft_print_content(struct node *head)
{
	struct node *ptr;
	ptr = head;
	while(ptr != NULL)
	{
		printf("%d\n", ptr->data); //we can't use printf
		ptr = ptr->link;
	}
	return 0;
}

void initiate_new_lists(struct node *head_of_stack1, int argc, char **argv)
{
	struct node *new;

	int	i;
	if (argc >= 3)
	{
		i = 2;
		head_of_stack1->data = ft_atoi(argv[1]);
		head_of_stack1->link = NULL;
		while(argv[i])
		{
			add_at_the_bottom(&head_of_stack1, ft_atoi(argv[i]));
			i++;
		}
	}
	else
		printf("%d", ft_atoi(argv[1]));
}

/* !there's a 0 initiated int he stack2, how to remove it? */
/* calculate negative numbers */
int	main(int argc, char **argv)
{
	struct node *head_stack1;
	struct node *head_stack2;

	if (argc < 2)
		return (-1);
	head_stack1 = malloc(sizeof(struct node));
	head_stack2 = malloc(sizeof(struct node));
	initiate_new_lists(head_stack1, argc, argv);




// --------- TESTING
	printf("Starting point of stack1: \n");
	ft_print_content(head_stack1); // that's just for us to see the input/output;
	printf("-------------------------\n");
	printf("Stack1 after sa: \n");
	sa(head_stack1);
	ft_print_content(head_stack1);
	printf("-------------------------\n");
	printf("Removed data: %d\n", pop(&head_stack1));
	printf("Stack1 after pop: \n");
	ft_print_content(head_stack1);
	printf("-------------------------\n");
	printf("Stack1 after pb: \n");
	pb(&head_stack1, &head_stack2);
	pb(&head_stack1, &head_stack2);
	pb(&head_stack1, &head_stack2);
	ft_print_content(head_stack1);
	printf("Stack2 after pb: \n");
	ft_print_content(head_stack2);
// --------- TESTING
    return (0);
}