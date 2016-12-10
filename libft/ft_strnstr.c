/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:47:12 by jmoucade          #+#    #+#             */
/*   Updated: 2016/11/05 14:47:21 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int		len_to_find;
	int		i;
	int		j;

	i = 0;
	len_to_find = ft_strlen(to_find);
	if (len_to_find == 0)
		return ((char *)str);
	while (i < (int)len && str[i])
	{
		j = 0;
		while (i + j != (int)len && str[i + j] == to_find[j] && str[i + j])
		{
			if (j == len_to_find - 1)
				return ((char *)str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
