NAME = poly_animals 

CXX = c++
CXXFLAGS= -Wall -Werror -Wextra -std=c++98 -fsanitize=address -pedantic

SRCS = main.cpp ./srcs/Dog.cpp ./srcs/Cat.cpp ./srcs/Animal.cpp ./srcs/WrongCat.cpp ./srcs/WrongAnimal.cpp 

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

run: $(NAME)
	make re && clear && ./$(NAME)
