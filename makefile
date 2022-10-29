SRC = main.cpp \
Point.cpp \
AverageFunction.cpp \
Structs.cpp \
Function.cpp

SRC_FOLDER = src/
INCLUDES_FOLDER = includes
OBJ_FOLDER = obj
OBJ= $(SRC:.cpp=.o)
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INCLUDES_FOLDER)
NAME = AverageFunction


all: $(NAME)

$(NAME):
	$(CC) -c $(addprefix $(SRC_FOLDER), $(SRC)) $(FLAGS)
	$(CC) -o $(NAME) $(OBJ) $(FLAGS)
	mkdir $(OBJ_FOLDER)
	mv $(OBJ) $(OBJ_FOLDER)

clean:
	rm -rf $(OBJ_FOLDER)


fclean: clean
	rm -f $(NAME)

re: fclean all