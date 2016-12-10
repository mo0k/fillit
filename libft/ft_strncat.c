/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:44:52 by jmoucade          #+#    #+#             */
/*   Updated: 2016/11/05 14:44:53 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dest, const char *src, int nb)
{
	int		len;
	int		count;

	len = ft_strlen(dest);
	count = 0;
	while (src[count] && count < nb)
	{
		dest[len + count] = src[count];
		count++;
	}
	dest[len + count] = '\0';
	return (dest);
}
