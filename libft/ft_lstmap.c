/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:46:09 by mtaouil           #+#    #+#             */
/*   Updated: 2021/03/25 15:59:45 by mtaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*elt;

	new_list = NULL;
	while (lst)
	{
		elt = ft_lstnew(f(lst->content));
		if (!elt)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}		
		ft_lstadd_back(&new_list, elt);
		lst = lst->next;
	}
	return (new_list);
}
