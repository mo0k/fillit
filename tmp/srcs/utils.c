#include "fillit.h"

/*
**	- This function delete the list of tetriminos.
*/

void	delete_lst_tetri(t_tetri *tetri)
{
	if (tetri)
		delete_lst_tetri(tetri->next);
	free(tetri);
}

void	delete_map_tetri(char **map)
{
	int y;

	y = 0;
	while (map[y])
	{
		free(map[y]);
		y++;
	}
	free(map);
}

void 	init_tetri_placed(t_tetri *tetri)
{
	while (tetri)
	{
		tetri->placed = 0;
		tetri->tested = 0;
		tetri = tetri->next;
	}
}

void 	init_tetri_start(t_tetri *tetri)
{
	while (tetri)
	{
		tetri->tested = 0;
		tetri = tetri->next;
	}
}

size_t	ft_lstlen(t_tetri *tetri)
{
	int 	i;
	i = 0;
	while (tetri)
	{
		++i;
		tetri = tetri->next;
	}
	return (i);
}
