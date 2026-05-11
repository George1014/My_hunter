##
## EPITECH PROJECT, 2025
## my_hunter
## File description:
## Makefile
##

SRC	=	src/main.c			\
		src/game.c			\
		src/game_states.c	\
		src/vehicle.c		\
		src/explosion.c		\
		src/input.c			\
		src/draw.c			\
		src/update.c		\
		src/update_round.c	\
		src/score.c			\
		src/help.c			\
		src/init.c			\
		src/init_textures.c	\
		src/init_sprites.c	\
		src/init_text.c		\
		src/init_audio.c	\
		src/cleanup.c		\
		src/menu.c			\
		src/menu_input.c	\
		src/menu_transition.c \
		src/highscore.c		\
		src/highscore_text.c \
		src/text_init.c		\
		src/menu_draw.c		\
		src/pause_draw.c	\
		src/string_utils.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

CFLAGS	=	-Wall -Wextra -I./include -I/opt/homebrew/include
LDFLAGS	=	-L/opt/homebrew/lib -lcsfml-graphics -lcsfml-window \
		-lcsfml-system -lcsfml-audio -lm

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
