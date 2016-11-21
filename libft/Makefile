# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amazurie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 13:11:07 by amazurie          #+#    #+#              #
#    Updated: 2016/11/21 11:11:23 by amazurie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
SRC = ft_itoa.c ft_memccpy.c ft_putchar_fd.c ft_strcat.c ft_striter.c \
ft_strncmp.c ft_strsub.c ft_atoi.c ft_memchr.c ft_putendl.c ft_strchr.c \
ft_striteri.c ft_strncpy.c ft_strtrim.c ft_bzero.c ft_memcmp.c \
ft_putendl_fd.c ft_strclr.c ft_strjoin.c ft_strnequ.c ft_tolower.c \
ft_isalnum.c ft_memcpy.c ft_putnbr.c ft_strcmp.c ft_strlcat.c ft_strnew.c \
ft_toupper.c ft_isalpha.c ft_memdel.c ft_putnbr_fd.c ft_strcpy.c ft_strlen.c \
ft_strnstr.c ft_isascii.c ft_memmove.c ft_putstr.c ft_strdel.c ft_strmap.c \
ft_strrchr.c ft_isdigit.c ft_memset.c ft_putstr_fd.c ft_strdup.c ft_strmapi.c \
ft_strsplit.c ft_isprint.c ft_memalloc.c ft_putchar.c ft_strequ.c ft_strncat.c \
ft_strstr.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
ft_lstmap.c ft_isspace.c ft_isblank.c ft_isupper.c ft_islower.c ft_strndup.c \
ft_strtrimc.c ft_strnjoin.c
FLAGS = -Wall -Wextra -Werror
OSRC = $(SRC:.c=.o)
HEADER = libft.h

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OSRC)
	ranlib $(NAME)

%.o: %.c
	$(CC) -o $@ $(FLAGS) -c $<

clean:
	-rm -f $(OSRC)

fclean: clean
	-rm -f $(NAME)

re: fclean all
