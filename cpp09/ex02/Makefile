NAME = PmergeMe
SRC = main.cpp PmergeMe.cpp
OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
CC = c++
CFLAGS =
HEADER = PmergeMe.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re : fclean all

run: all
	valgrind ./PmergeMe `shuf -i 1-1000 -n 3000 | tr "\n" " "`
