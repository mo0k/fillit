/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 09:12:59 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/05 12:13:53 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t i;
	size_t j;

	j = 0;
	i = ft_strlen(dst);
	while (src[j] && n > 0)
	{
		dst[i] = src[j];
		i++;
		j++;
		n--;
	}
	dst[i] = '\0';
	return (dst);
}
