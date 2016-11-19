#include "fillit.h"
#include "libft.h"

int	main(int ac, char **av)
{
	t_tetri	*pieces;
	char	**map;
	//int	ret;

	if (ac != 2)
	    return (usageerror());
	if (!(pieces = get_pieces(av[1])))
	    return (print_error());
	map = generate_map(4);
	map = first_resolve(map, pieces);
//	display_map(map);
//	place_tetri(map, pieces->hash, 0, 1);
//	display_map(map);
//	delete_map(map);
	close(ac);
	return (0);
}
