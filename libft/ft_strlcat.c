/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:41:23 by jmoucade          #+#    #+#             */
/*   Updated: 2016/11/05 14:41:24 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	count;
	unsigned int	len_dest;
	unsigned int	len_src;

	count = 0;
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (size == len_dest || size == len_dest + 1)
		return (len_dest + len_src);
	else if (size < len_dest)
		return (len_src + size);
	else
	{
		while (len_dest < size + 1 && count < size - len_dest - 1)
		{
			dest[len_dest + count] = src[count];
			count++;
		}
		dest[len_dest + count] = '\0';
		return (len_dest + len_src);
	}
}
