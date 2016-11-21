/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:22:48 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/10 12:56:38 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*str;

	if (!s || !f)
		return (NULL);
	if (!(str = (char *)ft_memalloc(ft_strlen((char *)s) + 1)))
		return (NULL);
	i = -1;
	while (s[++i])
		str[i] = f(s[i]);
	return (str);
}
