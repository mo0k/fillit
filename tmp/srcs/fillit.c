
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 22:52:04 by jmoucade          #+#    #+#             */
/*   Updated: 2016/11/07 12:23:35 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "input.h"
#include "resolve.h"

# define ERROR printf("error\n")

int main(int ac, char **av)
{
	t_map	*map;
	t_tetri	*tetri;
	int size_map;
	int ret;

	size_map = 4;
	if (ac < 2 || ac > 2)
		return (0);
	if (!(tetri = check_input(av[1])))
	{
		ERROR;
		return (0);
	}
	map = add_map(size_map);
	while (!(ret = resolve(map, tetri)))
	{
		//display_map(map->map);
		init_tetri_placed(tetri);
		delete_map(map);
		map = add_map(++size_map);
	}
	display_map(map->map);
	delete_map(map);
	delete_lst_tetri(tetri);
	return (0);
}
