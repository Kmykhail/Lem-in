/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 21:29:36 by kmykhail          #+#    #+#             */
/*   Updated: 2017/10/26 21:29:38 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	int		k;

	k = 0;
	i = 0;
	while (i < n)
	{
		if (((unsigned char*)s)[i] == (unsigned char)c)
		{
			k = 1;
			return ((void*)&((unsigned char*)s)[i]);
		}
		i++;
	}
	if (k == 0)
		return (NULL);
	return (((unsigned char*)s));
}
