CPP = clang++
HPP = Fixed.hpp
CPPFLAGS = -Wall -Werror -Wextra
NAME = fix

OBJ =	main.o \
		Fixed.o

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
