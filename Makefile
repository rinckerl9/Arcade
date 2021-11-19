##
## EPITECH PROJECT, 2021
## Arcade
## File description:
## Makefile
##

NAME	=	arcade

CXX		=	g++
CXXFLAGS	+=	-I./core/include
CXXFLAGS	+=	-Wall -Wextra -g
CXXFLAGS	+=	-ldl -fno-gnu-unique

SRC		=	./core/src/main.cpp		\
			./core/src/Error.cpp	\
			./core/src/DLLoader.cpp	\
			./core/src/Core.cpp		\
			./core/src/LibChecker.cpp	\
			./core/src/Object.cpp

OBJ		=	$(SRC:.cpp=.o)

all: core graphicals games

core:	$(NAME)

$(NAME):	$(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS)

graphicals:
	@make graphics -C ./lib/

games:
	@make games -C ./lib/

clean:
	rm -f $(OBJ)
	@make clean -C ./lib/

fclean:
	rm -f $(NAME)
	@make fclean -C ./lib/

re: clean fclean all