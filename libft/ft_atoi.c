/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 20:45:09 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/14 12:37:49 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	long	i;
	long	nb;
	int		neg;

	i = 0;
	nb = 0;
	neg = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		nb += str[i] - '0';
		if (ft_isdigit(str[i + 1]))
			nb *= 10;
		i++;
	}
	(neg == 1) ? nb *= -1 : 0;
	return (nb);
}
