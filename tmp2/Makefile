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
SRC = fillit.c input_check.c gesterror.c utils.c
FLAGS = -Wall -Wextra -Werror
OSRC = $(SRC:.c=.o)
INCLUDE = libft

all: $(NAME)

$(NAME): make -C $(INCLUDE)
	$(CC) $(FLAGS) -c $(SRC) -o $(NAME)

clean: make clean -C $(INCLUDE)
	-rm -f $(OSRC)

fclean: clean
	make fclean -C libf $(INCLUDE)
	-rm -f $(NAME)

re: fclean all
