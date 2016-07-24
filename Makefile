##
## gfx_wolf3d/Makefile for wolf in /home/wyzlic_a
##
## Made by Dimitri Wyzlic
## Login   <wyzlic_a@epitech.net>
##
## Started on  Fri May  6 19:02:51 2016 Dimitri Wyzlic
## Last update Sun Jul 24 16:04:45 2016 Dimitri Wyzlic
##

CC		= cc

RM		= rm -f

NAME		= wolf3d

CFLAGS		= -Wall -I inc -Wextra -ansi -pedantic -W -Werror

LIBLAPIN_PATH	= -I/home/${USER}/.froot/include \
		  -L/home/${USER}/.froot/lib \
		  -llapin -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -lstdc++ -ldl -lm

SRC		= tcore/tekpixel.c \
		  tcore/vecnorme.c \
		  tcore/go.c \
		  src/main.c \
		  src/my_swap.c \
		  src/my_line.c \
		  src/do_raycast.c \
		  src/init_stru.c \
		  src/move_maths.c \
		  src/eff_starfield.c \
		  src/fuck_const.c \
		  src/my_getnbr.c \
		  src/load_ini.c \
		  src/get_field_ini.c \
		  src/change_map.c \
		  src/utils_key.c \
		  src/my_putchar.c \
		  src/my_putstr.c \
		  src/minmap.c \
		  src/reset_minmap.c \
		  src/do_slomo.c \
		  src/draw_cross.c \
		  src/do_disco.c \
		  src/main_key.c \
		  src/display_c_pos.c \
		  src/gunfire.c \
		  src/load_sound.c \
		  src/put_block.c \
		  src/strafe.c

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LDFLAGS) $(LIBLAPIN_PATH)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY :  all clean fclean re
