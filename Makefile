##
## EPITECH PROJECT, 2022
## B-OOP-400-BRU-4-1-tekspice-guillaume.janssens [WSL: Ubuntu-20.04]
## File description:
## Makefile
##

RM	=	rm -f

SRC	=	src/main.cpp		\
		src/Gate/4001.cpp	\

OBJ	=	$(SRC:.cpp=.o)

CXXFLAGS	=	-std=c++2a -Wall -Wextra -I src/ -I include/

NAME	=	nanotekspice

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CXX) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all