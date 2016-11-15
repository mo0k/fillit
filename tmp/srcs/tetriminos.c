#include "tetriminos.h"

/*
**	- This function converts and malloc the string pointed to double array.
**	- The string pointed must be a valid tetrimino.
*/

char			**get_tetri_map(char *buf)
{
	char		**tetri_map;
	int			y;
	int			x;

	y = 0;
	if (!(tetri_map = (char **)malloc(sizeof(char*) * 4 + 1)))
		return (NULL);
	while (*buf)
	{
		if (!(tetri_map[y] = (char *)malloc(sizeof(char) * 4 + 1)))
		{
			free(tetri_map);
			return (NULL);
		}
		x = 0;
		while (*buf != 10)
		{
			tetri_map[y][x++] = *buf;
			buf++;
		}
		tetri_map[y++][x] = '\0';
		buf++;
	}
	tetri_map[y] = NULL;
	return (tetri_map);
}

/*
**	- This function converts the double array to struct s_tetri and
**	copy the coordinates of the tetriminos in strucu s_tetri.
**	- Delete double array.
*/

t_tetri			*create_tetri(char **tetri_map, char id_tetri)
{
	t_tetri		*tetri;
	t_point		master;
	int			flag;
	int 		y;
	int 		x;

	y = 0;
	flag = -1;
	if(!(tetri = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	while (tetri_map[y])
	{
		x = 0;
		while (tetri_map[y][x])
		{
			if (flag >= 0 && tetri_map[y][x] == '#')
			{
				set_point(&tetri->point[flag++], x - master.x, y - master.y);
				set_tetri(tetri, id_tetri, 0, 0);
			}
			if (flag == -1 && tetri_map[y][x] == '#')
			{
				set_point(&master, x, y);
				flag++;
			}
			x++;
		}
		y++;
	}
	delete_map_tetri(tetri_map);
	return (tetri);
}

/*
**	- This function add the new tetrimino in the list.
**	- Return the list of tetriminos.
*/

t_tetri			*add_tetri(t_tetri *tetri, t_tetri *new_tetri)
{
	t_tetri		*begin;

	begin = tetri;
	if (tetri == NULL)
	{
		new_tetri->next = tetri;
		tetri = new_tetri;
		new_tetri->begin = tetri;
	}
	else
	{
		
		while (begin->next)
			begin = begin->next;
		new_tetri->begin = tetri;
		new_tetri->next = begin->next;
		begin->next = new_tetri;
	}
	return (tetri);
}

void			set_point(t_point *point, int x, int y)
{
	point->x = x;
	point->y = y;
}

void				set_tetri(t_tetri *tetri, char id, int placed, int tested)
{
	tetri->id = id;
	tetri->placed = placed;
	tetri->tested = tested;
}

