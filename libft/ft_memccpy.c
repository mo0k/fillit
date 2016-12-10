/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:24:14 by jmoucade          #+#    #+#             */
/*   Updated: 2016/11/05 14:24:16 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;
	unsigned char	x;
	unsigned int	i;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	x = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		ptr_dst[i] = ptr_src[i];
		if (ptr_src[i] == x)
			return (ptr_dst + i + 1);
		i++;
	}
	return (NULL);
}
