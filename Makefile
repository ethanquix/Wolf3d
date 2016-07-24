##
## gfx_wolf3d/Makefile for wolf in /home/wyzlic_a
##
## Made by Dimitri Wyzlic
## Login   <wyzlic_a@epitech.net>
##
## Started on  Fri May  6 19:02:51 2016 Dimitri Wyzlic
## Last update Sun Jun  5 22:09:14 2016 Dimitri Wyzlic
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
		  main.c \
		  my_swap.c \
		  my_line.c \
		  do_raycast.c \
		  init_stru.c \
		  move_maths.c \
		  eff_starfield.c \
		  fuck_const.c \
		  my_getnbr.c \
		  load_ini.c \
		  get_field_ini.c \
		  change_map.c \
		  utils_key.c \
		  my_putchar.c \
		  my_putstr.c \
		  minmap.c \
		  reset_minmap.c \
		  do_slomo.c \
		  draw_cross.c \
		  do_disco.c \
		  main_key.c \
		  display_c_pos.c \
		  gunfire.c \
		  load_sound.c \
		  put_block.c \
		  strafe.c

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
