
NAME = cub3D 
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
INCLUDE = -I includes -I libft -I .
LINK = -L ./libft -l ft -L./mlx -lmlx -framework OpenGL -framework AppKit
LIBFTPATH = ./Libft
RM = rm -f
MAKE = make

ifeq ($(DEBUG), TRUE)
	CFLAGS -= -Werror
endif
#head
HEAD = ./includes/cub3d.h

SRC_PATH = srcs/
SRC_FILES = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\
		parse/set_player_pos.c parse/check_border.c  parse/check_news.c parse/check_type.c\
		main.c init_contents.c set_arg.c set_map.c execute_dda.c\
		test.c\
		util.c util2.c \
		execute/draw_bg.c execute/check_hit.c execute/draw_map.c execute/execute.c execute/get_ray_dist.c execute/key_wasd.c execute/main_loop.c execute/on_key_press.c execute/set_delta.c execute/set_side.c execute/stop_game.c execute/ver_line.c
 
SRCS = $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJS = $(patsubst %.c,%.o,$(SRCS))

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS) $(HEAD)
	$(MAKE) -C $(LIBFTPATH) BONUS_RULE=TRUE all
	$(CC) $(CFLAGS) $(LINK) $(OBJS) -o $@

all: $(NAME)

clean:
	$(MAKE) -C $(LIBFTPATH) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFTPATH) fclean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
