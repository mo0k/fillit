#include "fillit.h"
#include "libft.h"

void		delete_map(char **map)
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

char			**ft_realloc_map(char **map, int add_size)
{
	int			size;
	int			new_size;
	char		**new_map;
	int			i;

	i = 0;
	size = ft_strlen(map[0]);
	new_size = size + add_size;
	if (!(new_map = (char**)ft_memalloc(sizeof(char*) * (new_size + 1))))
		return (NULL);
	while (i < new_size)
	{
//		printf("i \n");
		new_map[i] = (char*)ft_memalloc(new_size + 1);
		ft_memset(new_map[i], '.', new_size);
		if (i < size)
		{
//		    printf("p \n");
		    ft_memcpy(new_map[i], map[i], size);
		}
		i++;
	}
	new_map[i] = NULL;
	//new_map[new_size - 1][new_size - 1] = '*';
	//delete_map(map);
	return (new_map);
}

char			**generate_map(size_t size)
{
	char		**map;
	int			y;
//	int			x;

	if (!(map = (char **)malloc(sizeof(char*) * size + 1)))
		return (NULL);
	y = 0;
	while (y < (int)size)
	{
//		x = 0;
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
		ft_putstr(*y);
		ft_putchar('\n');
		y++;
	}
}
