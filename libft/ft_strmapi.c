/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:27:06 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/10 12:50:26 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	if (!s || !f)
		return (NULL);
	if (!(str = (char *)ft_memalloc(ft_strlen((char *)s) + 1)))
		return (NULL);
	i = -1;
	while (s[++i])
		str[i] = f(i, (char)s[i]);
	str[i] = '\0';
	return (str);
}
