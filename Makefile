##
## EPITECH PROJECT, 2018
## makefile
## File description:
## yes
##

ORI	=	src/*.c

NAME	=	my_hunter

$(NAME): $(ORI)
		gcc $(ORI) -o $(NAME) -l csfml-system -l csfml-graphics -l csfml-window -l csfml-audio -l csfml-network

clean:

fclean: clean
		rm -f $(NAME)

re: fclean all

all: $(NAME)

.PHONY : all clean fclean re
