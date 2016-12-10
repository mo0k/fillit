/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:38:35 by jmoucade          #+#    #+#             */
/*   Updated: 2016/11/04 16:38:37 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max || !(tab = (int*)malloc(sizeof(int) * (max - min))))
		return (0);
	i = 0;
	while (min < max)
		tab[i++] = min++;
	return (tab);
}
