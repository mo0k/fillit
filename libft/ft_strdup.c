/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 17:02:16 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/08 12:16:17 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;

	if (!(str = (char *)ft_memalloc(ft_strlen(s1) + 1)))
		return (NULL);
	ft_memcpy(str, s1, ft_strlen(s1) + 1);
	return (str);
}
