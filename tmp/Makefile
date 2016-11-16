CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = fillit

DIR_INCLUDES = ./includes

DIR_SRCS = ./srcs

SRCS = $(DIR_SRCS)/fillit.c				\
		$(DIR_SRCS)/input.c				\
		$(DIR_SRCS)/map.c				\
		$(DIR_SRCS)/resolve.c			\
		$(DIR_SRCS)/string.c			\
		$(DIR_SRCS)/tetriminos.c 		\
		$(DIR_SRCS)/utils.c

OBJ = $(SRCS:%.c=%.o)

all: $(NAME)
	#$(CC) $(CFLAGS) -o $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRCS) -I $(DIR_INCLUDES) -o $(NAME)

clean:
	/bin/rm -f $(DIR_SRCS)/*.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
