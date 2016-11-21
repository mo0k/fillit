/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 16:39:00 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/09 11:18:42 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;
	char	*bg;

	bg = (char *)big;
	i = 0;
	j = 0;
	if (!little[j] || (!little && !big))
		return (bg);
	while (bg[i])
	{
		if (bg[i] == little[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
		if (!little[j])
			return (&bg[i - j]);
	}
	return (NULL);
}
