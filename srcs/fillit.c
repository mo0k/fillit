/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:17:20 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/23 15:06:18 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int	main(int ac, char **av)
{
	t_tetri	*pieces;
	char	**map;
	char	*buff;
	int		fd;
	int		nbpieces;

	if (ac != 2)
		return (usageerror());
	if (!(pieces = (t_tetri *)ft_memalloc(sizeof(t_tetri))))
		return (print_error());
	if (!(fd = open(av[1], O_RDONLY)))
		return (print_error());
	if (!(buff = (char *)ft_memalloc(BUFF_SIZE + 1)))
		return (print_error());
	if (!(pieces = get_pieces(fd, pieces, buff, &nbpieces)))
		return (print_error());
	close(ac);
	nbpieces = (nbpieces > 7) ? 6 : nbpieces - 1;
	nbpieces = (nbpieces > 11) ? 7 : nbpieces;
	nbpieces = (nbpieces > 13) ? 9 : nbpieces;
	if ((map = generate_map(nbpieces)))
		resolve(map, pieces, 0, 0);
	delete_pieces(pieces);
	delete_map(map);
	return (0);
}
