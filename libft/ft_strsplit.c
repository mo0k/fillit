/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:48:23 by jmoucade          #+#    #+#             */
/*   Updated: 2016/11/05 14:48:24 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *str, char const c)
{
	int		ct;
	int		nbr;

	nbr = 0;
	ct = 0;
	while (str[ct])
	{
		if (ct > 0 && str[ct] == c && str[ct - 1] != c)
			nbr++;
		ct++;
	}
	if (str[ct] == '\0' && str[ct - 1] != c && str[ct - 1] != 0)
		nbr++;
	return (nbr);
}

static int	len_word(char const *str, char const c)
{
	int		len;

	len = 0;
	if (!str || !c)
		return (0);
	while (*str++ != c)
	{
		len++;
		if (*str == c || *str == '\0')
			return (len);
	}
	return (len);
}

static char	*get_start(char *str, char const c)
{
	while (*str == c)
		str++;
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	*str;
	char	*start;
	int		word;
	int		nbr_word;

	word = 0;
	if (!s || !c)
		return (NULL);
	str = (char *)s;
	nbr_word = count_word(str, c);
	if (!(tab = (char**)malloc(sizeof(char*) * nbr_word + 1)))
		return (NULL);
	while (word < nbr_word)
	{
		start = get_start(str, c);
		if (!(tab[word++] = ft_strsub(start, 0, len_word(start, c))))
			return (NULL);
		str = start + len_word(start, c);
	}
	*(tab + nbr_word) = NULL;
	return (tab);
}
