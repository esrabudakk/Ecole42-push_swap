NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

SRC = libft_utils.c libft.c rules1.c rules2.c push_swap_utils.c push_swap_utils2.c push_swap.c
OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:	
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
