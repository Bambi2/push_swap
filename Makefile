NAME		=	push_swap

LIBFT_PATH	=	libft/

LIBFT		=	$(LIBFT_PATH)libft.a

SRCS		=	score_counting.c			push_swap.c					push_swap_actions.c\
				push_swap_actions_plus.c	moving.c					main.c\
				input_check.c				array_utils/convert_copy.c	array_utils/sort_check_arr.c

OBJ			=	$(SRCS:%.c=%.o)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

.PHONY		=	all clean fclean re

all:	$(LIBFT) $(NAME)

$(LIBFT):
	make -s -C $(LIBFT_PATH)

$(NAME):	$(OBJ)
	$(CC) $(CGLAGS) $(OBJ) -o $(NAME)
%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -s -C $(LIBFT_PATH) clean
	rm -f $(OBJ)

fclean:	clean
	make -s -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re:	fclean all
