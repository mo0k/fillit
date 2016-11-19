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
	    display_map(map);
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

/*char	**resolve(char **map, t_tetri *pieces, int maxsize)
{
}*/

char	**first_resolve(char **map, t_tetri *piece)
{
    int	    i;
    int	    j;
    int	    placed;

    if (!piece->hash)
	return (map);
    i = 0;
    placed = 0;
    while (map[i])
    {
	j = 0;
	while(map[i][j])
	{
	    if (place_tetri(map, piece->hash, i, j))
	    {
		if ((map = first_resolve(map, piece->next)))
		    return (map);
		placed = 1;
	    }
	    j++;
	}
	i++;
    }
//    if (!placed)
//	map = ft_realloc_map(map, 1);
    if (!placed)
	first_resolve(map, piece);
    return (NULL);
}
