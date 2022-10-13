# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daskim <daskim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 12:01:12 by jeoan             #+#    #+#              #
#    Updated: 2022/09/29 11:34:29 by daskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isalpha.c\
	   ft_isdigit.c\
	   ft_isalnum.c\
	   ft_isascii.c\
	   ft_isprint.c\
	   ft_strlen.c\
	   ft_memset.c\
	   ft_bzero.c\
	   ft_memcpy.c\
	   ft_memmove.c\
	   ft_strlcpy.c\
	   ft_strlcat.c\
	   ft_toupper.c\
	   ft_tolower.c\
	   ft_strchr.c\
	   ft_strrchr.c\
	   ft_strcmp.c\
	   ft_strncmp.c\
	   ft_memchr.c\
	   ft_memcmp.c\
	   ft_strnstr.c\
	   ft_atoi.c\
	   ft_calloc.c\
	   ft_strdup.c\
	   ft_substr.c\
	   ft_strjoin.c\
	   ft_strtrim.c\
	   ft_split.c\
	   ft_itoa.c\
	   ft_strmapi.c\
	   ft_striteri.c\
	   ft_putchar_fd.c\
	   ft_putstr_fd.c\
	   ft_putendl_fd.c\
	   ft_putnbr_fd.c

BONUS_SRCS = ft_lstnew.c\
			 ft_lstadd_front.c\
			 ft_lstsize.c\
			 ft_lstlast.c\
			 ft_lstadd_back.c\
			 ft_lstdelone.c\
			 ft_lstclear.c\
			 ft_lstiter.c\
			 ft_lstmap.c

OBJS = $(patsubst %.c,%.o,$(SRCS))

BONUS_OBJS = $(patsubst %.c,%.o,$(BONUS_SRCS))

ifeq ($(BONUS_RULE), TRUE)
	OBJS += $(BONUS_OBJS)
endif

NAME = libft.a
CC = cc
RM = rm -f
AR = ar -rcs
CFLAGS = -Wall -Wextra -Werror

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

bonus :
	make BONUS_RULE=TRUE all

.PHONY : all clean fclean re bonus
