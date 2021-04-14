/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaouil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 08:43:51 by mtaouil           #+#    #+#             */
/*   Updated: 2021/03/25 16:28:09 by mtaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str2;

	if (n == 0)
		return (0);
	i = 0;
	str = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (i < n - 1 && str[i] == str2[i])
		i++;
	return (str[i] - str2[i]);
}
