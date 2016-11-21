/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:15:40 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/10 15:10:13 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lennb(int n)
{
	int i;

	i = 0;
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	long	i;
	long	tmp;

	tmp = (long)n;
	if (n < 0)
		tmp *= -1;
	i = (long)ft_lennb(tmp) + (n < 0);
	if (!(str = ft_strnew(i + 1)))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	while (tmp)
	{
		str[i] = tmp % 10 + '0';
		tmp /= 10;
		i--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
