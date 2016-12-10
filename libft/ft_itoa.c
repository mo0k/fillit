/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:23:13 by jmoucade          #+#    #+#             */
/*   Updated: 2016/11/05 14:23:39 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	long	nbr;
	int		i;
	long	div;
	char	*ret;

	i = 0;
	div = 1;
	nbr = (long)n;
	if (!(ret = ft_strnew(ft_nbrlen(n))))
		return (NULL);
	if (nbr == 0)
		ret[i] = '0';
	if (nbr < 0)
	{
		nbr *= -1;
		ret[i++] = '-';
	}
	while (nbr / div != 0)
		div *= 10;
	while (div - 1)
	{
		ret[i++] = (nbr - (nbr / div * div)) / (div / 10) + 48;
		div /= 10;
	}
	return (ret);
}
