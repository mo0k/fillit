#include "fillit.h"

int	main(int ac, char **av)
{
	//t_list	*map;
	t_tetri	*pieces;
	//int	ret;

	if (ac != 2)
	    return (usageerror());
	if (!(pieces = get_pieces(av[1])))
	    return (print_error());
	close(ac);
	return (0);
}
