/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:00:24 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/08 11:06:53 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t size)
{
	size_t i;

	i = -1;
	while (src[++i] && i < size)
		dest[i] = src[i];
	i--;
	while (++i < size)
		dest[i] = '\0';
	return (dest);
}
