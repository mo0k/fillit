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
	map = generate_map(6);
	place_tetri(map, pieces->hash, 0, 0);
//	pieces = pieces->next;
//	place_tetri(map, pieces->hash, 0, 1);
	display_map(map);
	close(ac);
	return (0);
}
