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

char    **ft_split(char *str, char separator);