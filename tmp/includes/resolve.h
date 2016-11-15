#ifndef RESOLVE_H
# define RESOLVE_H

# include "tetriminos.h"


	int	is_solved(t_tetri *tetri);
	int	chk_pos(t_map *map, t_point coord, t_tetri *tetri, int nbr_point);
	int	is_placed(t_map *map, t_point coord, t_tetri *t, int nbr_t);
	int	place(t_map *map, t_point coord, t_tetri *t, int nbr_t);
	int	resolve(t_map *map, t_tetri *tetri);

#endif