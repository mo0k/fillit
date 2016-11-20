#include "fillit.h"
#include "libft.h"

int	place_tetri(char **map, t_hash *hashs, int xstart, int ystart)
{
	int	    i;

	i = ft_strlen(map[0]);
	if (!hashs->next)
		return (1);
	if (xstart + hashs->x < i && ystart + hashs->y < i)
	{
		if (!(map[xstart + hashs->x][ystart + hashs->y] == '.'))
			return (0);
		if (map[xstart + hashs->x][ystart + hashs->y] == '.')
		{
			map[xstart + hashs->x][ystart + hashs->y] = hashs->letter;
			if (!(place_tetri(map, hashs->next, xstart, ystart)))
			{
				map[xstart + hashs->x][ystart + hashs->y] = '.';
				return (0);
			}
		}
	}
	else
		return (0);
	return (1);
}

void	delete_letter(char **map, int c)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c){
				map[i][j] = '.';
			}
			j++;
		}
		i++;
	}
}

int 	resolve(char **map, t_tetri *piece, int i, int j)
{
	int	    all_tested;

	all_tested = 0;
	if (!piece->hash)
		display_map(map);
	if (!piece->hash)
		return (1);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while(map[i][++j])
		{
			if (place_tetri(map, piece->hash, i, j))
			{
				if ((resolve(map, piece->next, i, j)))
					return (1);
				delete_letter(map, piece->hash->letter);
			}
		}
	}
	if (piece->hash->letter == 'A')
	   all_tested = 1;
	if (all_tested)
		map = ft_realloc_map(map, 1);
	if (all_tested)
		resolve(map, piece, 0, 0);
	return (0);
}
