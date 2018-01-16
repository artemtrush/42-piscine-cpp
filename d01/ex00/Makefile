CPP = clang++
HPP = Pony.hpp
CPPFLAGS = -Wall -Werror -Wextra
NAME = pony

OBJ =	main.o \
		Pony.o

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
