CPP = 	clang++
HPP =	Object.hpp \
		Border.hpp \
		Player.hpp \
		Enemy.hpp \
		Bullet.hpp

CPPFLAGS = -Wall -Werror -Wextra
NAME = 	ft_retro

OBJ =	main.o \
		Object.o \
		Border.o \
		Player.o \
		Enemy.o \
		Bullet.o \


all: $(NAME)

$(NAME):  $(OBJ)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJ) -lncurses

%.o: %.cpp $(HPP)
	$(CPP) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all