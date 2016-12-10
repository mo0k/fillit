/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:35:54 by jmoucade          #+#    #+#             */
/*   Updated: 2016/11/05 14:35:56 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int len;
	int i;

	i = -1;
	len = ft_strlen(dest);
	while (*(src + ++i))
		dest[len + i] = src[i];
	dest[len + i] = '\0';
	return (dest);
}
