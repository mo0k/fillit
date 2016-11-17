#include "map.h"

static void		delete_map(char **map)
{
	int 		y;

	y = 0;
	while (map[y])
	{
		free(map[y]);
		y++;
	}
	free(map);
}

static size_t	map_size(char **map)
{
	size_t		i;

	i = 0;
	while (*map)
	{
		i++;
		map++;
	}
	printf("i: %d\n", (int)i);
	return (i);
}

char			**ft_reallloc_map(char **map, int add_size)
{
	int			size;
	char		**new_map;
	int			i;

	i = 0;
	size = map_size(map);
	if (!(new_map = (char**)ft_memalloc(size + add_size + 1)))
		return (NULL);
	while (i < size + add_size)
	{
		new_map[i] = (char*)ft_memalloc(size + add_size + 1);
		if (i < size)
		{
			ft_memcpy(new_map[i], map[i], size);
			if (size < size + add_size)
				ft_memset(new_map[i] + size, '.', add_size);
		}
		if (i < size + add_size)
			ft_memset(new_map[i], '.', size + add_size);
		i++;
	}
	new_map[i] = NULL;
	//new_map[size + add_size - 1][size + add_size - 1] = '*';
	delete_map(map);
	return (new_map);
}

char			**generate_map(size_t size)
{
	char		**map;
	int			y;
	int			x;

	if (!(map = (char **)malloc(sizeof(char*) * size + 1)))
		return (NULL);
	y = 0;
	while (y < (int)size)
	{
		x = 0;
		if (!(map[y] = (char*)ft_memalloc(size + 1)))
		{
			free(map);
			return (NULL);
		}
		ft_memset(map[y], '.', size);
		map[y][size] = '\0';
		y++;
	}
	map[y] = NULL;
	return (map);
}

void			display_map(char **map)
{
	char 		**y;

	y = map;
	while (*y)
	{
		ft_putstr("%s\n", *y);
		y++;
	}
}
