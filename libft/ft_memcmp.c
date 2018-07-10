/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 12:19:42 by kmykhail          #+#    #+#             */
/*   Updated: 2017/10/27 12:19:46 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*one;
	unsigned char	*to;

	one = (unsigned char *)s1;
	to = (unsigned char *)s2;
	i = 0;
	if (i == n)
		return (0);
	if (i < n)
	{
		while (one[i] == to[i] && i < n - 1)
			i++;
	}
	return (one[i] - to[i]);
}
