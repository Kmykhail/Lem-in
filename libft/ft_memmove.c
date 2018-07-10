/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:38:09 by kmykhail          #+#    #+#             */
/*   Updated: 2017/10/26 15:38:11 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*n_dst;
	char	*n_src;

	n_dst = dst;
	n_src = (char*)src;
	if (n_dst > n_src)
	{
		while (len > 0)
		{
			n_dst[len - 1] = n_src[len - 1];
			len--;
		}
	}
	if (n_dst < n_src)
		ft_memcpy(n_dst, n_src, len);
	return (n_dst);
}
