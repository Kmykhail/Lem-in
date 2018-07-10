/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 15:28:21 by kmykhail          #+#    #+#             */
/*   Updated: 2017/10/28 15:28:23 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (i == n)
		return (0);
	while ((unsigned char)s1[i] == (unsigned char)s2[i] && \
		(unsigned char)s1[i] && (unsigned char)s2[i] && i < n - 1)
		i++;
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}
