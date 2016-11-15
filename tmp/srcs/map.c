#include "map.h"

char		**generate_map(size_t size)
{
	char	**map;
	int		y;
	int		x;

	if (!(map = (char **)malloc(sizeof(char*) * size + 1)))
		return (NULL);
	y = 0;
	while (y < (int)size)
	{
		x = 0;
		if (!(map[y] = (char *)malloc(sizeof(char) * size + 1)))
		{
			free(map);
			return (NULL);
		}
		while (x < (int)size)
		{
			map[y][x] = '.';
			x++;
		}
		map[y][x] = '\0';
		y++;
	}
	map[y] = NULL;
	return (map);
}

void	delete_map(t_map *map)
{
	int y;

	y = 0;
	while (map->map[y])
	{
		free(map->map[y]);
		y++;
	}
	free(map->map);
	free(map);
}

void	display_map(char **map)
{
	char **y;

	y = map;
	while (*y)
	{
		ft_putstr(*y);
		ft_putchar('\n');
		y++;
	}
}

t_map	*add_map(size_t	size)
{
	t_map	*ptr;

	if (!(ptr = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	ptr->map = generate_map(size);
	ptr->size = size;
	return (ptr);
}