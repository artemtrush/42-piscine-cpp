CPP = clang++
CPPFLAGS = -Wall -Werror -Wextra
NAME = identify

OBJ = main.o \
	Base.class.o

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
