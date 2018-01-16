CPP = 	clang++
HPP =	Brain.hpp \
		Human.hpp

CPPFLAGS = -Wall -Werror -Wextra
NAME = human

OBJ =	main.o \
		Brain.o \
		Human.o

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