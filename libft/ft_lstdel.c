/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:48:50 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/10 11:31:41 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	while ((*alst))
	{
		tmp = (*alst)->next;
		ft_lstdelone(alst, (*del));
		(*alst) = tmp;
	}
	free(tmp);
	*alst = NULL;
}
