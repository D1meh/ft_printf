/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 09:00:37 by mtaouil           #+#    #+#             */
/*   Updated: 2021/03/25 13:21:26 by mtaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*dest;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	i = -1;
	s = (unsigned char *)src;
	dest = (unsigned char *)dst;
	if (dest > s)
	{
		while (i + 1 < len)
		{
			dest[len - 1] = s[len - 1];
			len--;
		}
	}
	else
	{
		while (len > ++i)
			dest[i] = s[i];
	}
	return (dst);
}
