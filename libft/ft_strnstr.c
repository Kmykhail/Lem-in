/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:23:49 by kmykhail          #+#    #+#             */
/*   Updated: 2017/10/30 14:23:51 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dst, const char *src, size_t len)
{
	size_t	i;
	int		b;

	i = 0;
	if (src[i] == '\0' && dst[i] != '\0')
		return ((char*)dst);
	else if (src[i] == '\0' && dst[i] == '\0')
		return ((char*)dst);
	while (dst[i])
	{
		b = 0;
		while (dst[i + b] == src[b])
		{
			if ((src[b] == '\0' || src[b + 1] == '\0') && (i + b < len))
				return ((char*)dst + i);
			else if (i + b == len)
				return (NULL);
			b++;
		}
		i++;
	}
	return (NULL);
}
