/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:30:07 by kmykhail          #+#    #+#             */
/*   Updated: 2017/10/27 16:30:09 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	b;
	size_t	res;

	i = 0;
	b = 0;
	res = ft_strlen(src);
	while (dst[i] && i < size)
		i++;
	if (size > 0)
	{
		while (src[b] && i < size - 1)
		{
			dst[i] = src[b];
			i++;
			b++;
		}
	}
	if (b > 0)
	{
		dst[i] = '\0';
		return (res + i - b);
	}
	return (res + i);
}
