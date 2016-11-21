/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:44:42 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/09 13:12:17 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *m;

	if (!(m = (void *)malloc(sizeof(void) * size)))
		return (NULL);
	ft_bzero(m, size);
	return (m);
}
