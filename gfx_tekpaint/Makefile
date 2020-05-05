
NAME            =       tekpaint

LIB             =       -L/home/${USER}/.froot/lib/ -llapin \
                        -L/usr/local/lib \
                        -lsfml-audio \
                        -lsfml-graphics \
                        -lsfml-window \
                        -lsfml-system \
                        -lstdc++ -ldl \
                        -lm

FLAG            =       -g -W -Wall -Wextra -ansi -pedantic -I/home/${USER}/.froot/include/

SRC             =       $(wildcard ./src/tekpaint.c) \
			$(wildcard ./src/tekline.c) \
			$(wildcard ./src/tekpixel.c) \
			$(wildcard ./src/tekgetpixel.c) \
			$(wildcard ./src/my_addx.c) \
			$(wildcard ./src/my_strlen.c) \
			$(wildcard ./src/palette.c)\
			$(wildcard ./src/event_all.c)\
			$(wildcard ./src/draw_opt.c)\
			$(wildcard ./src/print_case.c)\
			$(wildcard ./src/load_bmp.c)\
			$(wildcard ./src/load_24_pix.c) \
			$(wildcard ./src/save_img_bmp.c) \
			$(wildcard ./src/options.c) \
			$(wildcard ./src/click.c) \
			$(wildcard ./src/loop.c) \
			$(wildcard ./src/key.c) \
			$(wildcard ./src/load_img.c) \
			$(wildcard ./src/save_tek.c) \
			$(wildcard ./src/paint_bucket_opt.c) \
			$(wildcard ./src/paint_bucket.c)

OBJ             =       $(SRC:.c=.o)

CC              =       gcc

all:            $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) $(LIB) -o $(NAME)
clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.c.o:
	$(CC) -c $< -o $@ $(FLAG)
