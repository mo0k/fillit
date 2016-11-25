/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gesterror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:17:31 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/25 20:10:50 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int	usageerror(void)
{
	ft_putstr("fillit usage: ./fillit target_file");
	return (0);
}

int	print_error(void)
{
	ft_putstr("error\n");
	return (0);
}
