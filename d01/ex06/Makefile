CPP = 	clang++
HPP =	HumanA.hpp \
		HumanB.hpp \
		Weapon.hpp \

CPPFLAGS = -Wall -Werror -Wextra
NAME = violence

OBJ =	main.o \
		HumanA.o \
		HumanB.o \
		Weapon.o

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