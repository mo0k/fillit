/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:18:53 by jmoucade          #+#    #+#             */
/*   Updated: 2016/11/05 14:18:58 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		ft_calcul(char *str, int sign)
{
	long		value;
	int			count;

	value = 0;
	count = 0;
	while ((*(str + count) >= '0' && *(str + count) <= '9'))
		value = value * 10 + (*(str + count++) - 48);
	return (sign * value);
}

static int		ft_is_charc_special(char c)
{
	int			count;
	char		tab_char_special[6];

	count = -1;
	while (++count < 5)
		tab_char_special[count] = count + 9;
	tab_char_special[count] = ' ';
	count = 0;
	while (tab_char_special[count])
	{
		if (c == tab_char_special[count])
			return (1);
		count++;
	}
	if (c == '+' || c == '-')
		return (2);
	else
		return (0);
}

int				ft_atoi(const char *str)
{
	int			n;
	int			sign;

	n = -1;
	sign = 1;
	while (ft_is_charc_special(*(str + (++n))) || ft_isdigit(*(str + n)))
	{
		if (*(str + n) == '+' || *(str + n) == '-')
		{
			if (*(str + n) == '-')
				sign = -1;
			if ((ft_is_charc_special(*(str + n - 1)) == 2 &&
					ft_is_charc_special(*(str + n)) == 2) ||
					ft_is_charc_special(*(str + n + 1)) == 1)
				return (0);
		}
		if (ft_isdigit(*(str + n)))
			return (ft_calcul((char *)str + n, sign));
	}
	return (0);
}
