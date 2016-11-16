#include "fillit.h"

/*
**	- This function check the numbers of '#' and '.' in the string pointed.
*/

static int			check_map(char *buf)
{
	int i = 0;
	int x = 0;
	int j = 0;
	char *pos;

	pos = buf;
	while (*pos)
	{
		if (i < 4 && *pos == '#')
			x++;
		if (i < 4 && *pos == '.')
			j++;
		if (i == 4 && *pos == 10)
			i = 0;
		else
			i++;
		pos++;
	}
	if (x != 4 || j != 12){
		return (0);
	}
	else
		return (1);
}

/*
**	- This function check if the coordinates's tetrimino are side by side.
**	- Return (1) if tetriminos is valid.
**	- Return (0) if tetriminos isn't valid.
*/

static int			tetri_isvalid(char *begin, char *cur, char *prev, int nbr_point)
{
	int		ret;
	ret = 0;
	if (*cur)
	{
		if (nbr_point == 4)
			ret =  1;
		if (!ret && *cur == '#' && *(cur + 1) == '#' && prev - 1 != cur)
			ret = tetri_isvalid(begin, cur + 1, cur, ++nbr_point);
		if (!ret && *cur == '#' && cur - begin > 5 && *(cur - 5) == '#' && prev + 5 != cur)
			ret = tetri_isvalid(begin, cur - 5, cur, ++nbr_point);
		if (!ret && *cur == '#' && cur - begin > 1 && *(cur - 1) == '#' && prev + 1 != cur)
			ret = tetri_isvalid(begin, cur - 1, cur, ++nbr_point);
		if (!ret && *cur == '#' && cur - begin < 14 && *(cur + 5) == '#' && prev - 5 != cur)
			ret = tetri_isvalid(begin, cur + 5, cur, ++nbr_point);
		if (*cur != '#')
			ret = tetri_isvalid(begin, cur + 1, cur + 1, nbr_point);
		if (!ret)
			nbr_point--;
		else
			return (ret);
	}
	return (ret);
}

/*
**	- This function open and read file what contains the differents tetriminos,
**	check all tetriminos. 
**	- Return the list of tetriminos if all tetriminos are valid.
**	- Return NULL if one tetriminos isn't valid
*/

t_tetri		*check_input(char *str)
{
	int		fd;
	char	buf[BUF_SIZE + 1];
	int		ret;
	int 	prev_ret;
	char	id;
	t_tetri	*tetri;

	id = 'A';
	if (!(fd = open(str, O_RDONLY)))
		return (NULL);
	if (!(tetri = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	tetri = NULL;
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		prev_ret = ret;
		if (((ret == 21 && buf[ret] == 0) || (ret == 20 && buf[ret] == 10)) &&
				(check_map(buf) && tetri_isvalid(buf, buf, buf, 1)))
			tetri = add_tetri(tetri, create_tetri(get_tetri_map(buf), id++));
		else
			return (NULL);
	}
	if (close(fd) == -1 || prev_ret != 20)
		return (NULL);
	return (tetri);
}