/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 09:34:52 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/08 17:17:17 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t tot;

	j = 0;
	i = ft_strlen(dst);
	tot = i + ft_strlen(src);
	if (i >= size)
		return (tot - i + size);
	size -= i;
	while (src[j] && size > 1)
	{
		dst[i] = src[j];
		i++;
		j++;
		size--;
	}
	dst[i] = '\0';
	return (tot);
}
