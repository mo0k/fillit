/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:35:18 by jmoucade          #+#    #+#             */
/*   Updated: 2016/11/05 14:35:19 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putstr(const char *str)
{
	int		i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}
