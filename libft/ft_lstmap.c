/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazurie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:58:43 by amazurie          #+#    #+#             */
/*   Updated: 2016/11/11 17:34:16 by amazurie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;

	if (!lst || !f)
		return (NULL);
	if (!(new = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	new = f(new);
	if (lst->next)
		new->next = ft_lstmap(lst->next, f);
	return (new);
}
