#include "fillit.h"
#include "libft/libft.h"

int	place_tetri(char **map, t_hash *hashs, char letter, int xstart, int ystart)
{
    t_hash   *tmp;

    if (!(tmp = (t_hash *)malloc(sizeof(t_hash))))
	return (0);
    tmp = hashs;
    if (!(map[xstart + tmp->x][ystart + tmp->y] == '.'))
	return (0);
    if (map[xstart + tmp->x][ystart + tmp->y] == '.')
    {
	map[xstart + tmp->x][ystart + tmp->y] = letter;
	if (!(place_tetri(map, tmp->next, letter, xstart, ystart)))
	{
	    map[xstart + tmp->x][ystart + tmp->y] = '.';
	    return (0);
    }
    }
    free(tmp);
    return (1);
}
