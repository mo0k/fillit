/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 16:39:00 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/08 12:01:00 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*str;
	unsigned char		*cop;

	str = (unsigned char *)dest;
	cop = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		str[i] = cop[i];
		if (cop[i] == (unsigned char)c)
			return (&str[++i]);
		i++;
	}
	return (NULL);
}
