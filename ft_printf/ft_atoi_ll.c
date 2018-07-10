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

ptrdiff_t	ft_atoi_ll(const char *str)
{
	ptrdiff_t			result;
	size_t				i;
	ptrdiff_t			sign;

	i = 0;
	result = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\r' \
	|| str[i] == ' ' || str[i] == '\v' || str[i] == '\f')
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	while (ft_isdigit(str[i]))
		result = result * 10 + str[i++] - '0';
	return (result * sign);
}
