/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 09:53:26 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/12 10:05:42 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrimc(const char *s, char c)
{
	unsigned int	i;
	size_t			j;

	i = 0;
	j = 0;
	if (!s)
		return (ft_strsub(s, 0, 1));
	while (s[i] == c)
		i++;
	while (s[i + j])
		j++;
	j--;
	while (s[i + j] == c)
		j--;
	return (ft_strsub(s, i, j + 1));
}
