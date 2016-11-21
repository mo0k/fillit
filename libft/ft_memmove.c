/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 16:39:00 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/09 16:28:37 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *str;
	unsigned char *cop;

	str = (unsigned char *)dst;
	cop = (unsigned char *)src;
	if (str <= cop)
		return (ft_memcpy(dst, src, len));
	while (len--)
		str[len] = cop[len];
	return (dst);
}
