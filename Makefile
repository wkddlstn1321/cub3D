# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daskim <daskim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 20:11:51 by jeoan             #+#    #+#              #
#    Updated: 2022/10/04 19:02:53 by daskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
INCLUDE = -I includes -I libft -I .
LINK = -L ./libft -L $(READLINEPATH) -l ft -l readline -l history -l ncurses
LIBFTPATH = ./Libft
RM = rm -f
MAKE = make
DEBUG = false
READLINEPATH = ./readline
READLINE_VERSION = 8.2
READLINE_FILE = readline-$(READLINE_VERSION).tar.gz
READLINE_FTP = https://ftp.gnu.org/gnu/readline/$(READLINE_FILE)

ifeq ($(DEBUG), TRUE)
	CFLAGS -= -Werror
endif

SRC_PATH = srcs/
SRC_FILES = main.c\
			free.c\
			env/env.c\
			env/env_list.c\
			parse/tokens/tkn.c\
			parse/tokens/tkn_split.c\
			parse/tokens/tkn_env_replace.c\
			parse/tokens/tkn_dequote.c\
			parse/check_syntax.c\
			parse/parse.c\
			parse/commands/init_cmd_list.c\
			parse/commands/find_path.c\
			execute/heredoc.c\
			execute/tmpfile.c\
			execute/init_redirections.c\
			execute/set_redirections.c\
			execute/execute.c\
			execute/execute_cmd.c\
			execute/execute_builtin.c\
			is_file.c\
			utils.c\
			builtin/ft_echo.c\
			builtin/ft_cd.c\
			builtin/ft_pwd.c\
			builtin/ft_export.c\
			builtin/ft_export_util.c\
			builtin/ft_export_util2.c\
			builtin/ft_unset.c\
			builtin/ft_env.c\
			builtin/ft_exit.c\
			error/error.c\
			error/error2.c\
			signal/handle_signal.c\
			signal/initial_signal.c\

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

debug:
	$(MAKE) DEBUG=TRUE re

readline:
	$(RM) -r $(READLINEPATH)
	mkdir $(READLINEPATH)
	curl -O $(READLINE_FTP)
	tar -xf $(READLINE_FILE) --strip-components 1 -C $(READLINEPATH)
	$(RM) $(READLINE_FILE)
	cd $(READLINEPATH) && ./configure
	$(MAKE) -C $(READLINEPATH)

.PHONY: all clean fclean re debug readline
