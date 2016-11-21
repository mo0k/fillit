/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 16:39:00 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/08 10:06:46 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ch;

	i = 0;
	ch = (char *)s;
	while (ch[i])
	{
		if (ch[i] == (char)c)
			return (&ch[i]);
		i++;
	}
	if (ch[i] == (char)c)
		return (&ch[i]);
	return (0);
}
