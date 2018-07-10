/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:06:23 by kmykhail          #+#    #+#             */
/*   Updated: 2017/11/02 15:06:26 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;

	if (!s1 || !s2)
		return (0);
	if ((i = ft_strncmp((char*)s1, (char*)s2, n)) == 0)
		return (1);
	else
		i = 0;
	return (i);
}
