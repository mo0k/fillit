/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:01:36 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/10 13:03:29 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wds(char *str, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i])
			j++;
		while (str[i] != c && str[i])
			i++;
	}
	return (j + 1);
}

static char		**ft_split(char const *s, char **stab, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		j = 0;
		if (s[i] != c)
		{
			while (s[i + j] && s[i + j] != c)
				j++;
			stab[k++] = ft_strsub(s, i, j);
			i += j;
		}
		else
			while (s[i] && s[i] == c)
				i++;
		stab[k] = NULL;
	}
	return (stab);
}

char			**ft_strsplit(char const *s, char c)
{
	char			**stab;

	if (!s || !c)
		return (NULL);
	if (!(stab = (char **)ft_memalloc(sizeof(char **) * ft_wds((char *)s, c))))
		return (NULL);
	stab = ft_split(s, stab, c);
	return (stab);
}
