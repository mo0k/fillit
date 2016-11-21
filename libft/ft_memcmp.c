/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:26:13 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/08 12:08:11 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	*cp;

	tmp = (unsigned char *)s1;
	cp = (unsigned char *)s2;
	i = -1;
	while (++i < n)
		if (tmp[i] != cp[i])
			return (tmp[i] - cp[i]);
	return (0);
}
