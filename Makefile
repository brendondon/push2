SRCS	=	cheap_rotate.c check_input.c find_last.c \
			push_moves.c push_swap.c push_to_a.c rev_rotate.c \
			rotate_moves.c set_datas.c stack_starts.c start_list.c \
			swap_moves.c util_b.c

OBJS	=	$(SRCS:.c=.o)

CC		=	cc

NAME	=	push_swap

CFLAGS  = 	-Wall -Wextra -Werror -g

LIBFTA  = 	./libft/libft.a

LIBFTD  = 	./libft

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTA)
	$(CC) main.c $(CFLAGS) $(OBJS) $(LIBFTA) -o $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFTD)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTD)

re: fclean all

$(LIBFTA): $(LIBFTD)
	make -C $(LIBFTD)
