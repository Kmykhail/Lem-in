/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 13:05:01 by kmykhail          #+#    #+#             */
/*   Updated: 2017/12/17 14:23:17 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_ui(size_t n)
{
	char	*s;
	int		i;
	size_t	buff;

	i = 1;
	buff = n;
	while ((n = (n / 10)))
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i--] = '\0';
	if (buff == 0)
	{
		s[0] = '0';
		s[1] = '\0';
	}
	while (buff > 0)
	{
		s[i--] = buff % 10 + '0';
		buff /= 10;
	}
	return (s);
}
