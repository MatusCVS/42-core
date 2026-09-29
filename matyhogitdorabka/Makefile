NAME := push_swap

CC := cc
CFLAGS := -Wall -Wextra -Werror
AR := ar -rc
RM := rm -f

INC := includes/push_swap.h

SRC :=	new_stack.c \
        new_node.c \
        main.c \
        disorder.c \
        mode.c \
        stack_push.c \
        stack_rotate.c \
        stack_reverse_rotate.c \
        stacl_swap.c \
		radix_sort.c \

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(res) $(NAME) $(OBJ)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
