/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:42:33 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/08 10:44:14 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int num;

	if (n < 0)
		ft_putchar_fd('-', fd);
	num = 1;
	if (n > 0)
		n = n * -1;
	while (n / num < -9)
		num = num * 10;
	while (num > 0)
	{
		ft_putchar_fd((n / num % 10 * -1 + '0'), fd);
		num = num / 10;
	}
}
