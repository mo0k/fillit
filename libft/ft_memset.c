/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:45:06 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/08 11:34:26 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t				i;
	unsigned char		*str;

	str = (unsigned char *)b;
	i = -1;
	while (++i < len)
		str[i] = (unsigned char)c;
	return (b);
}
