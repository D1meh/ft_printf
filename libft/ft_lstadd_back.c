/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:06:58 by mtaouil           #+#    #+#             */
/*   Updated: 2021/03/25 15:50:36 by mtaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*elt;

	if (!alst)
		return ;
	if (*alst)
	{
		elt = ft_lstlast(*alst);
		elt->next = new;
	}
	else
		*alst = new;
}
