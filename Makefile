
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

SRC_PATH = srcs/
SRC_FILES = main.c util.c

SRCS = $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJS = $(patsubst %.c,%.o,$(SRCS))

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
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
