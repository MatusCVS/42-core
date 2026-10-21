NAME := push_swap
CHECKER := checker
CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f
LIBFT := libft/libft.a
COMMON := fill_stack.c new_node.c disorder.c stack_push.c \
          stack_rotate.c stack_reverse_rotate.c stack_swap.c mode.c
SORT := main.c radix_sort.c selection_sort.c chunk_based_sort.c bench.c \
		ft_printf_stderr.c
SRC := $(COMMON) $(SORT)
OBJ := $(SRC:.c=.o)
CHECKER_SRC := checker.c $(COMMON)
CHECKER_OBJ := $(CHECKER_SRC:.c=.o)

all: $(NAME)
$(LIBFT):
	$(MAKE) -C libft
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
#$(CHECKER): $(CHECKER_OBJ) $(LIBFT)
#	$(CC) $(CFLAGS) $(CHECKER_OBJ) $(LIBFT) -o $(CHECKER)
%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJ) checker.o
	$(MAKE) -C libft clean
fclean: clean
	$(RM) $(NAME) $(CHECKER)
	$(MAKE) -C libft fclean
re: fclean all
$(CHECKER): $(CHECKER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(CHECKER_OBJ) $(LIBFT) -o $(CHECKER)
bonus: $(CHECKER)
.PHONY: all clean fclean re