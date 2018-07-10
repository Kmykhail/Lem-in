/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:08:14 by kmykhail          #+#    #+#             */
/*   Updated: 2017/10/26 15:08:16 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	size_t			l;

	i = 0;
	l = 0;
	while (i < n)
	{
		((char*)dst)[i] = ((char*)src)[i];
		i++;
		if (((unsigned char*)dst)[i - 1] == (unsigned char)c)
			return ((void*)&((unsigned char*)dst)[i]);
	}
	return (NULL);
}
