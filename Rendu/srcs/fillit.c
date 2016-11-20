#include "fillit.h"
#include "libft.h"

int	main(int ac, char **av)
{
	t_tetri	*pieces;
	char	**map;

	if (ac != 2)
	    return (usageerror());
	if (!(pieces = get_pieces(av[1])))
	    return (print_error());
	map = generate_map(3);
	resolve(map, pieces, 0, 0);
	close(ac);
	return (0);
}
