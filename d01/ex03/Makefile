CPP = clang++
HPP = 	Zombie.hpp \
		ZombieHorde.hpp

CPPFLAGS = -Wall -Werror -Wextra
NAME = zombie

OBJ =	main.o \
		Zombie.o \
		ZombieHorde.o

all: $(NAME)

$(NAME):  $(OBJ)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp $(HPP)
	$(CPP) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all