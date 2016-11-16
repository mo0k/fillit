#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>

# include <stdio.h>

# define BUFF_SIZE 21


typedef struct	    s_tetri
{
    int		    w;
} t_tetri;

t_tetri	*get_pieces(char *av);
int	usageerror();
int	print_error();

#endif
