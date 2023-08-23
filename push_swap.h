#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

//static int	count_words(char *str, char separator);
//static int	countBits(struct node **stack);
//static char	*get_next_word(char *str, char separator);
char		**ft_split(char *str, char separator);
int			is_sorted(struct node **stack_a);
int			len(struct node **stack);
int			small_atoi(char *str);
int			bad_syntax(char *a);
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
void		error(struct node **stack, char **argv);
void		sort3(struct node **stack_a);
struct node	*get_next_min(struct node **stack_a);
struct node *find_last_node(struct node *node);


#endif