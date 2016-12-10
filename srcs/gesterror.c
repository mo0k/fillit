/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gesterror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:17:31 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/29 10:21:14 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int	usageerror(void)
{
	ft_putstr("fillit usage: ./fillit target_file\n");
	return (0);
}

int	print_error(void)
{
	ft_putstr("error\n");
	return (0);
}
