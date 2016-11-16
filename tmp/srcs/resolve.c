#include "fillit.h"

int		is_solved(t_tetri *tetri)
{
	while (tetri)
	{
		if (tetri->placed == 0)
			return (0);
		tetri = tetri->next;
	}
	return (1);
}

int		chk_pos(t_map *map, t_point coord, t_tetri *tetri, int nbr_point)
{
	int	x;
	int	y;

	x = tetri->point[nbr_point].x;
	y = tetri->point[nbr_point].y;
	if (((x + coord.x >= 0 && x + coord.x < (int)map->size) || coord.x == 0) &&
		((y >= 0 && y + coord.y < (int)map->size) || coord.y == 0) &&
		map->map[y + coord.y][x + coord.x] == '.')
		return (1);
	else
		return (0);
}

int 	is_placed(t_map *map, t_point coord, t_tetri *t, int nbr_t)
{
	int	ret;
	int	x;
	int	y;

	ret = 0;
	t->tested = 1;
	if (nbr_t == 1)
		map->map[coord.y][coord.x] = t->id;
	if (!ret && nbr_t < 4 && chk_pos(map, coord, t, nbr_t - 1))
	{
		x = t->point[nbr_t - 1].x;
		y = t->point[nbr_t - 1].y;
		map->map[y + coord.y][x + coord.x] = t->id;
		if (nbr_t < 3)
			ret = is_placed(map, coord, t, nbr_t+1);
		if (nbr_t == 3)
			ret = 1;
		if (!ret)
			map->map[y + coord.y][x + coord.x] = '.';
	}
	if (!ret)
		map->map[coord.y][coord.x] = '.';
	else
		return (1);
	return (0);
}
//27 Lignes
int 	place(t_map *map, t_point coord, t_tetri *t, int nbr_t)
{
	int ret;

	ret = 0;
	if (!t->tested)
		nbr_t--;
	if (!nbr_t)
		ret = 1;
	if (t->placed == 0 && t->tested == 0 && is_placed(map, coord, t, 1))
	{
		t->placed = 1;
		ret = 1;
	}
	if (t->placed == 1 && !t->next)
		init_tetri_start(t->begin);
	if (!ret)
	{
		if (!t->next)
		{
			init_tetri_start(t->begin);
			ret = place(map, coord, t->begin, nbr_t);
		}
		else
			ret = place(map, coord, t->next, nbr_t);
	}
	if (is_solved(t->begin))
		ret = 2;
	return(ret);
}

int 	resolve(t_map *map, t_tetri *tetri)
{
	int y;
	int x;
	int ret;
	int nbr_tetri;
	t_point	coord;
	
	nbr_tetri = ft_lstlen(tetri);
	ret = 0;
	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == '.'){
				coord.x = x;
				coord.y = y;
				ret = place(map, coord, tetri, nbr_tetri);
			}
			if (ret == 2)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
