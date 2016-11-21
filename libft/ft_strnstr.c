/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 16:39:00 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/09 11:19:54 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*bg;

	bg = (char *)big;
	i = 0;
	j = 0;
	if (!little[j] || (!little && !bg))
		return (bg);
	while (bg[i] && i < len)
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
