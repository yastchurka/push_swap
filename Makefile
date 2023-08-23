NAME = push_swap
# CHECK = checker

SRCS = freeing.c\
		ft_split.c\
		indexing.c\
		push_swap.c\
		radix_sort.c\
		initiating.c\
		len_and_last_node.c\
		push.c\
		rotate.c\
		small_atoi.c\
		errors.c\
		swap.c\
		sort3.c\

OBJS = $(SRCS:.c=.o)

CC = cc -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o $(NAME)

# $(CHECK): $(CHECK_OBJS)
# 		$(CC) $(CHECK_OBJS) libft/libft.a -o $(CHECK)

clean:
		rm -f $(OBJS)
#rm -f $(CHECK_OBJS)

fclean: clean
		rm -f $(NAME)
#rm -f $(CHECK)

re: fclean all

.PHONY: all clean fclean re