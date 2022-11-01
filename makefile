BRAIN_FILE = main.cpp \
Point.cpp \
AverageFunction.cpp \
Structs.cpp \
Function.cpp

INCLUDES_FOLDER = -Iincludes/brain \
-Iincludes/display

SRC = $(addprefix src/brain/, $(BRAIN_FILE))

OBJ_FOLDER = obj
OBJ= $(BRAIN_FILE:.cpp=.o)
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 $(INCLUDES_FOLDER)
NAME = AverageFunction


all: $(NAME)

$(NAME):
	$(CC) -c $(SRC) $(FLAGS)
	$(CC) -o $(NAME) $(OBJ) $(FLAGS)
	mkdir $(OBJ_FOLDER)
	mv $(OBJ) $(OBJ_FOLDER)

clean:
	rm -rf $(OBJ_FOLDER)


fclean: clean
	rm -f $(NAME)

re: fclean all