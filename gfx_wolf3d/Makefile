
NAME            =       wolf3d

LIB             =       -L/home/${USER}/.froot/lib/ -llapin \
                        -L/usr/local/lib \
                        -lsfml-audio \
                        -lsfml-graphics \
                        -lsfml-window \
                        -lsfml-system \
                        -lstdc++ -ldl \
                        -lm

FLAG            =       -W -Wall -Wextra -I/home/${USER}/.froot/include/ -I./include/

SRC             =       $(wildcard ./src/alloc.c) \
			$(wildcard ./src/disp.c) \
			$(wildcard ./src/wolf3d.c) \
			$(wildcard ./src/tekline.c) \
			$(wildcard ./src/tekpixel.c) \
			$(wildcard ./src/tekgetpixel.c) \
			$(wildcard ./src/my_addx.c) \
			$(wildcard ./src/my_strlen.c) \
			$(wildcard ./src/my_getnbr.c) \
			$(wildcard ./src/vecnorm.c) \
			$(wildcard ./src/go.c)

OBJ             =       $(SRC:.c=.o)

CC              =       gcc

all:            $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) $(LIB) -o $(NAME)
clean:
	rm -Rf $(OBJ)

fclean:	clean
	rm -Rf $(NAME)

re:	fclean all

.c.o:
	$(CC) -c $< -o $@ $(FLAG)
