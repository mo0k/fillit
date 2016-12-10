/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:50:12 by jmoucade          #+#    #+#             */
/*   Updated: 2016/11/05 14:50:14 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_separator(char c)
{
	return (c == ' ' || c == '\t' || c == '\n') ? (1) : (0);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*start;
	char	*stop;
	char	*str;

	i = 0;
	str = NULL;
	if (s)
	{
		while (is_separator(*(s + i)))
			i++;
		start = (char *)s + i;
		i = ft_strlen(s) - 1;
		while (start != s + i && is_separator(*(s + i)))
			i--;
		stop = (char *)s + i;
		if (start >= stop)
			len = 1;
		else
			len = stop - start + 1;
		if ((str = ft_strnew(len)))
			str = ft_strncpy(str, start, len);
	}
	return (str);
}
