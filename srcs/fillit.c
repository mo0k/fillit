/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:17:20 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/21 11:58:42 by amazurie         ###   ########.fr       */
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

	if (ac != 2)
		return (usageerror());
	if (!(pieces = (t_tetri *)ft_memalloc(sizeof(t_tetri))))
		return (print_error());
	if (!(fd = open(av[1], O_RDONLY)))
		return (print_error());
	if (!(buff = (char *)ft_memalloc(BUFF_SIZE + 1)))
		return (print_error());
	if (!(pieces = get_pieces(fd, pieces, buff)))
		return (print_error());
	close(ac);
	map = generate_map(3);
	resolve(map, pieces, 0, 0);
	return (0);
}
