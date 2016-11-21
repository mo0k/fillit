/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:34:51 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/10 13:15:08 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if ((!s1 && s2) || (!s2 && n > 0))
		return (0);
	if (!s2 && !s2)
		return (1);
	if ((s1 == s2) || !s2[i])
		return (1);
	while (s1[i] == s2[i] && s1 && s2 && i < n)
	{
		if (!s1[i] && !s2[i])
			return (1);
		i++;
	}
	if (i == n)
		return (1);
	return (0);
}
