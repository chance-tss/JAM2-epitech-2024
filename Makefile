##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	JAM

$(NAME):	all

all:
	gcc -o $(NAME) $(SRC) -l csfml-graphics \
	-l csfml-window -l csfml-system -l csfml-audio

clean:
	rm -f $(OBJ) *~ *#

fclean:	clean
	rm -f $(NAME)

re:	fclean all
