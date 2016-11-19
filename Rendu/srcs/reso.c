#include "fillit.h"
#include "libft.h"

int	place_tetri(char **map, t_hash *hashs, int xstart, int ystart)
{
    t_hash  *tmp;
    int	    i;

    i = ft_strlen(map[0]);
    if (!hashs->next)
	return (1);
    if (!(tmp = (t_hash *)malloc(sizeof(t_hash))))
	return (0);
    tmp = hashs;
    if (xstart + tmp->x < i && ystart + tmp->y < i)
    {
	if (!(map[xstart + tmp->x][ystart + tmp->y] == '.'))
	    return (0);
	if (map[xstart + tmp->x][ystart + tmp->y] == '.')
	{
	    map[xstart + tmp->x][ystart + tmp->y] = tmp->letter;
	    if (!(place_tetri(map, tmp->next, xstart, ystart)))
	    {
		map[xstart + tmp->x][ystart + tmp->y] = '.';
		free(tmp);
		return (0);
	    }
	}
    }
    else
    {
	free(tmp);
	return (0);
    }
    free(tmp);
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
    if (!placed)
	map = ft_realloc_map(map, 1);
    if (!placed)
	first_resolve(map, piece);
    return (NULL);
}
