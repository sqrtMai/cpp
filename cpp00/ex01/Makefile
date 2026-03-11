NAME = phonebook
SRC = phonebook.cpp
OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
CC = c++ -std=c++98
CFLAGS = -Wall -Wextra -Werror
HEADER = phonebook.hpp

all: $(NAME)

$(NAME): $(OBJ) phonebook.hpp
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re : fclean all
