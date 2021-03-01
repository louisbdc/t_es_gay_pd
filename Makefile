##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	src/sokoban.c	\
		src/sokoban_2.c	\
		src/main.c	\
		src/lib/*.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

all: $(NAME)

$(NAME):
	gcc $(SRC) -Wall -Wextra -I include -o $(NAME) -lncurses -g3

clean:
	rm -f $(OBJ)
	rm -f *~

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
