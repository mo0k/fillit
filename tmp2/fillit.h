#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>

# include <stdio.h>

# define BUFF_SIZE 21

typedef	struct	    t_hash
{
    int		    x;
    int		    y;
    struct  t_hash  next;
}		    t_hash;

typedef struct	    s_tetri
{
    struct t_hash   *hash;
    char	    letter;
    struct s_tetri *next;
}		    t_tetri;

t_tetri		   *get_pieces(char *av);
int		    tetri_isvalid(char **tetri);
int		    check_tetri(char *buff);
t_tetri		    *store_tetri(t_tetri *tetri, char *buff);
int		    usageerror();
int		    print_error();
void		    init(int i, int j, int k, int l);

#endif
