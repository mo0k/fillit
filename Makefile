# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 13:11:07 by jmoucade          #+#    #+#              #
#    Updated: 2016/11/25 11:41:08 by amazurie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INC_PATH = includes

SRC_PATH = srcs

SRC =	$(SRC_PATH)/fillit.c 		\
		$(SRC_PATH)/gesterror.c 	\
		$(SRC_PATH)/utils.c 		\
		$(SRC_PATH)/map.c 			\
		$(SRC_PATH)/input_check.c 	\
		$(SRC_PATH)/reso.c 			\
		$(SRC_PATH)/tetri_handle.c

OSRC = $(SRC:.c=.o)

LIB_PATH = libft
LIB = libft/libft.a

NO_COLOR=\x1b[0m
OK_COLOR=\x1b[32;01m

all: $(NAME)

$(NAME): $(LIB) $(OSRC)
	@echo "Compiling..."
	@$(CC) $(CFLAGS) $(OSRC) -o $@ -L $(LIB_PATH) -lft
	@echo "$(OK_COLOR)$@ compiled.$(NO_COLOR)"

$(LIB):
	@echo "Compiling libft..."
	@make -C $(LIB_PATH)
	@echo "Librairy compiled."

%.o: %.c
	@$(CC) $(CFLAGS) -I $(LIB_PATH) -I $(INC_PATH) -c -o $@ $?
	@echo "Linking file $@"

clean:
	@make clean -C $(LIB_PATH)
	@/bin/rm -f $(OSRC)
	@echo "Cleaning temporary files."

fclean: clean
	@make fclean -C $(LIB_PATH)
	@/bin/rm -f $(NAME)
	@echo "Delete $(NAME) file."

re: fclean all
