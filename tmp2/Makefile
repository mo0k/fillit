# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amazurie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 13:11:07 by amazurie          #+#    #+#              #
#    Updated: 2016/11/12 14:09:48 by amazurie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
SRC = fillit.c
FLAGS = -Wall -Wextra -Werror
OSRC = $(SRC:.c=.o)

all: $(NAME)

$(NAME): make -C libft
	$(CC) $(FLAGS) -c $(SRC) -o $(NAME)

clean: make clean -C libft
	-rm -f $(OSRC)

fclean: clean
	make fclean -C libft
	-rm -f $(NAME)

re: fclean all
