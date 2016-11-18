#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>

# include <stdio.h>

# define BUFF_SIZE 21

typedef	struct	    t_hash
{
    int		    x;
    int		    y;
    struct  t_hash  *next;
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
int		    usageerror();
int		    print_error();
//void		    init(int i, int j, int k, int l);
int		    locate_tetri(t_tetri *piece, char **tetri);
t_tetri		    *store_tetri(t_tetri *piece, char *buff);
t_hash		    *save_tetri(char **tetri, int xstart, int ystart);
int		    place_tetri(char **map, t_hash *hashs, char letter, int i, int j);
char		**generate_map(size_t size);
char		**ft_reallloc_map(char **map, int add_size);
void	display_map(char **map);

#endif
