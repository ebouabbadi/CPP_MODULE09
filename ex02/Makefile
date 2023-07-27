NAME = PmergeMe

SRC = main.cpp PmergeMe.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++ #-std=c++98 #-Wall -Wextra -Werror

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o:%.cpp  PmergeMe.hpp
	$(CC) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all