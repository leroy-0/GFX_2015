##
## Makefile for tekadventure in /home/tekm/tek1/gfx_tekadventure
##
## Made by Tekm
## Login   <tekm@epitech.net>
##
## Started on  Thu Apr 14 17:57:44 2016 Tekm
## Last update Wed Apr 20 15:16:04 2016 
##

NAME            =       tekadventure

LIB             =       -L/home/${USER}/.froot/lib/ -llapin \
                        -L/usr/local/lib \
                        -lsfml-audio \
                        -lsfml-graphics \
                        -lsfml-window \
                        -lsfml-system \
                        -lstdc++ -ldl \
                        -lm

FLAG            =       -W -Wall -Wextra -ansi -pedantic -I/home/${USER}/.froot/include/ -I./include/

SRC             =       source_file/main.c \
			source_file/load_24_pix.c \
			source_file/load_bmp.c \
			source_file/load_img.c \
			source_file/tekpixel.c \
			source_file/tektext.c \
			source_file/text_intro.c \
			source_file/tekresize.c \
			source_file/my_strncmp.c \
			source_file/event.c \
			source_file/tekcut.c \
			source_file/tekplus.c \
			source_file/my_strlen.c \
			source_file/tekcoldel.c \
			source_file/tekblit.c \
			source_file/move_my_player.c \
			source_file/click_manager.c \
			source_file/init_main.c \
			source_file/move_func.c

OBJ             =       $(SRC:.c=.o)

CC              =       gcc

all:            $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) $(LIB) -o $(NAME)
clean:
	rm -f $(OBJ)
	rm -f vgcore*

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.c.o:
	$(CC) -c $< -o $@ $(FLAG)
