/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:39:30 by jmoucade          #+#    #+#             */
/*   Updated: 2016/11/05 14:39:31 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	int		ct;
	char	*ptr;

	ct = 0;
	ptr = NULL;
	if (!(ptr = (char*)malloc(sizeof(char) * ft_strlen(src) + 1)))
		return (NULL);
	while (src[ct])
	{
		ptr[ct] = src[ct];
		ct++;
	}
	ptr[ct] = '\0';
	return (ptr);
}
