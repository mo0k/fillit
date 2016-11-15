#ifndef TETRIMINOS_H
# define TETRIMINOS_H

# include <stdlib.h>
# include "map.h"

typedef struct		s_point
{
	int	x;
	int	y;
}					t_point;

typedef struct		s_tetri
{
	t_point			point[3];
	char			id;
	int				placed;
	int				tested;
	struct s_tetri	*begin;
	struct s_tetri	*next;
}					t_tetri;


char				**get_tetri_map(char *buf);
t_tetri				*create_tetri(char **tetri_map, char id);
t_tetri				*add_tetri(t_tetri *tetri, t_tetri *new_tetri);
void				set_point(t_point *point, int x, int y);
void				set_tetri(t_tetri *tetri, char id, int placed, int tested);
void				delete_lst_tetri(t_tetri *tetri);
void				delete_map_tetri(char **map);
void				init_tetri_start(t_tetri *tetri);
size_t				ft_lstlen(t_tetri *tetri);
void				init_tetri_placed(t_tetri *tetri);

#endif