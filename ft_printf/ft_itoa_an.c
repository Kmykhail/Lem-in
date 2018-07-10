/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:02:42 by exam              #+#    #+#             */
/*   Updated: 2018/01/19 15:00:22 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_len_arr(ptrdiff_t nbr)
{
	int				i;
	size_t			ui;

	i = 0;
	ui = 0;
	if (!nbr)
		return (1);
	if (nbr < 0)
	{
		ui = nbr * (-1);
		i++;
		while (ui > 0)
		{
			ui /= 10;
			i++;
		}
		return (i);
	}
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

void	ft_result(char **arr, int len, int sign, ptrdiff_t nbr)
{
	size_t	ui;
	char	*buff;

	ui = (nbr < 0) ? (nbr * -1) : nbr;
	if (!ui)
	{
		(*arr) = ft_strdup("0");
		return ;
	}
	buff = (char*)malloc(sizeof(char) * (len + 1));
	buff[len--] = '\0';
	while (len >= 0 && ui != 0)
	{
		buff[len] = (ui % 10) + '0';
		ui /= 10;
		len--;
	}
	if (sign < 0)
		buff[len] = '-';
	(*arr) = ft_strdup(buff);
	ft_strdel(&buff);
}

char	*ft_itoa_an(ptrdiff_t nbr)
{
	int		len;
	char	*arr;
	int		sign;

	sign = (nbr < 0) ? -1 : 1;
	len = ft_len_arr(nbr);
	ft_result(&arr, len, sign, nbr);
	return (arr);
}
