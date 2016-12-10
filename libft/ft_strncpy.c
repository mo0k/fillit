/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:45:30 by jmoucade          #+#    #+#             */
/*   Updated: 2016/11/05 14:45:31 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	len;
	int		state;

	state = 0;
	len = 0;
	while (len < n)
	{
		if (!state && !src[len])
			state = 1;
		if (state)
			dest[len] = '\0';
		else
			dest[len] = src[len];
		len++;
	}
	return (dest);
}
