##
## EPITECH PROJECT, 2021
## Arcade Libraries
## File description:
## Makefile
##

CXX	=	g++
CXXFLAGS	+=	-I../core/include/
CXXFLAGS	+=	-Wall -Wextra
CXXFLAGS	+=	-fPIC -shared

## Graphical Libraries
LNAME1	=	arcade_ncurses.so
LNAME1_SRC	=	./graphics/ncurses/src/Ncurses.cpp
LNAME1_OBJ	=	./graphics/ncurses/src/Ncurses.o
LNAME2	=	arcade_sdl2.so
LNAME2_SRC	=	./graphics/sdl2/src/SDL2.cpp
LNAME2_OBJ	=	./graphics/sdl2/src/SDL2.o
LNAME3	=	arcade_sfml.so
LNAME3_SRC	=	./graphics/sfml/src/SFML.cpp
LNAME3_OBJ	=	./graphics/sfml/src/SFML.o
## Graphical Libraries

## Game Libraries
GNAME1	=	arcade_nibbler.so
GNAME1_SRC	=	./games/nibbler/src/Nibbler.cpp
GNAME1_OBJ	=	./games/nibbler/src/Nibbler.o
GNAME2	=	arcade_pacman.so
GNAME2_SRC	=	./games/pacman/src/Pacman.cpp
GNAME2_OBJ	=	./games/pacman/src/Pacman.o
## Game Libraries 

all: graphics games

graphics: ncurses sdl2 sfml

ncurses: $(LNAME1_OBJ)
	$(CXX) -o $(LNAME1) $(LNAME1_SRC) $(CXXFLAGS) -lncurses

sdl2: $(LNAME2_OBJ)
	$(CXX) -o $(LNAME2) $(LNAME2_SRC) $(CXXFLAGS)

sfml: $(LNAME3_OBJ)
	$(CXX) -o $(LNAME3) $(LNAME3_SRC) $(CXXFLAGS) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

games: nibbler pacman

nibbler: $(GNAME1_OBJ)
	$(CXX) -o $(GNAME1) $(GNAME1_SRC) $(CXXFLAGS)

pacman: $(GNAME2_OBJ)
	$(CXX) -o $(GNAME2) $(GNAME2_SRC) $(CXXFLAGS)

clean:
	rm -f $(LNAME1_OBJ) $(LNAME2_OBJ) $(LNAME3_OBJ)
	rm -f $(GNAME1_OBJ) $(GNAME2_OBJ)

fclean:
	rm -f $(LNAME1) $(LNAME2) $(LNAME3)
	rm -f $(GNAME1) $(GNAME2)

re: clean fclean all