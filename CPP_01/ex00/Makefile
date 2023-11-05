NAME = BraiiiiiiinnnzzzZ

CXX = c++
CXXFLAGS= -Wall -Werror -Wextra -std=c++98 -fsanitize=address -pedantic

SRCS = main.cpp ./srcs/Zombie.cpp ./srcs/randomChump.cpp  ./srcs/newZombie.cpp

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

subject:
	xdg-open https://cdn.intra.42.fr/pdf/pdf/89749/en.subject.pdf
