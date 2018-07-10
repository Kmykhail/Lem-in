/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:39:09 by kmykhail          #+#    #+#             */
/*   Updated: 2017/10/28 12:39:12 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *dst, const char *src)
{
	int i;
	int b;

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
			if (src[b] == '\0' || src[b + 1] == '\0')
				return ((char*)dst + i);
			b++;
		}
		i++;
	}
	return (NULL);
}
