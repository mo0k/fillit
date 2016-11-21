/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:51:13 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/14 10:22:31 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	i;
	size_t			j;

	i = 0;
	j = 0;
	if (!s)
	{
		str = ft_strsub(s, 0, 1);
		return (str);
	}
	while (ft_isblank(s[i]) || s[i] == '\n')
		i++;
	while (s[i + j])
		j++;
	j--;
	while (s[i] && (ft_isspace(s[i + j]) || s[i] == '\n'))
		j--;
	str = ft_strsub(s, i, j + 1);
	return (str);
}
