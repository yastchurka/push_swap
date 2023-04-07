#include <stdio.h>
#include <stdlib.h>



struct node { //change name to sth else
	int		data;
	int		index;
	struct	node *link;
};

void	sa(struct node *head);
int	ft_print_content(struct node *head);

int node_counter(struct node **head1)
{
	struct node *temp;
	int         counter;

	if (!head1)
		printf("Error message!"); // chagnge to ft_printf
	temp = *head1;
	counter = 1;
	while (temp->link != NULL)
	{
		temp = temp->link;
		counter++;
	}
	return (counter);
}

int	sort(struct node **head1)
{
	int 		count;
	struct node *head;

	head = *head1;
	count = node_counter(head1);
	printf("Number count: %d\n", count);
	if (count == 2)
	{
		if (head->data > head->link->data)
			sa(head);
		else
			return (0);
	}
	//else radzik sort
}