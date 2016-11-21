/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 16:39:00 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/08 12:44:07 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ch;

	ch = (char *)s;
	i = ft_strlen(ch);
	while (i > 0)
	{
		if (ch[i] == (char)c)
			return (&ch[i]);
		i--;
	}
	if (ch[i] == (char)c)
		return (&ch[i]);
	return (0);
}
