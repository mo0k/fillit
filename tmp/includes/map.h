#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include "string.h"
#include <stdio.h>

typedef struct		s_map
{
	char	**map;
	size_t	size;
}					t_map;

	char		**generate_map(size_t size);
	void		delete_map(t_map *map);
	void		display_map(char **map);
	t_map		*add_map(size_t	size);

#endif