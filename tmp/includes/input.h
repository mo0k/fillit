#ifndef INPUT_H
# define INPUT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "tetriminos.h"
#include <stdio.h>

# define BUF_SIZE 21

t_tetri		*check_input(char *str);
int			check_map(char *buf);
int			tetri_isvalid(char *begin, char *cur, char *prev, int nbr_point);

#endif