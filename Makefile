CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = push_swap
SRCS = push_swap.c push_swap_move.c manage_stacks.c check_values.c\
		push_swap_operations_a.c push_swap_operations_b.c push_swap_operations_both.c\
		sort.c sort_utils.c split.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re