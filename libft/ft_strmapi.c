/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:44:38 by jmoucade          #+#    #+#             */
/*   Updated: 2016/11/05 14:44:40 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	str = NULL;
	i = -1;
	if (s && f)
	{
		if ((str = ft_strnew(ft_strlen(s))))
		{
			while (s[++i])
				str[i] = f(i, s[i]);
		}
	}
	return (str);
}
