/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 09:15:34 by jmoucade          #+#    #+#             */
/*   Updated: 2016/11/06 09:15:35 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lstlen(t_list *lst)
{
	int		ret;
	t_list	*begin;

	ret = 0;
	begin = lst;
	while (begin)
	{
		ret++;
		begin = begin->next;
	}
	return (ret);
}
