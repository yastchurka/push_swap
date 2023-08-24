#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648

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

int			is_sorted(struct node **stack_a);
int			len(struct node **stack);
long		small_atoi(char *str);
int			bad_syntax(char *a);
char		**ft_split(char *str, char separator);
void		sorting(struct node **stack_a, struct node **stack_b, int argc);
void		index_all(struct node **stack_a);
void		append_node(struct node **stack, int nbr);
void		initiate_stack(struct node **a, char *argv[]);
void		break_me_free(struct node **stack);
void		radix_sort(struct node **stack_a, struct node **stack_b);
void		rotate(struct node **stack);
void		rotate_down(struct node **stack);
void		swap(struct node **stack);
void		push(struct node **stack_a, struct node **stack_b);
void		pa(struct node **a, struct node **b);
void		pb(struct node **a, struct node **b);
void		error(struct node **stack);
void		sort3(struct node **stack_a);
void		radek_sort(struct node **stack_a, struct node **stack_b);
void		free_stack(struct node **stack);
int		check_for_duplicates(struct node **stack, int nb);
struct node	*get_next_min(struct node **stack_a);
struct node *find_last_node(struct node *node);

#endif