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

int		ft_len_res(size_t v, size_t b)
{
	int l;

	l = 0;
	if (v < b)
		return (1);
	while (v >= b)
	{
		l++;
		v /= b;
	}
	l++;
	return (l);
}

void	ft_zerkalo(char **s)
{
	int		i;
	int		l;
	char	*zrk;

	i = (int)ft_strlen((*s));
	l = 0;
	zrk = (char*)malloc(sizeof(char) * (i + 1));
	i--;
	while (i >= 0)
		zrk[l++] = (*s)[i--];
	zrk[l] = '\0';
	ft_strdel(&(*s));
	*s = ft_strdup(zrk);
	free(zrk);
}

char	*ft_itoa_base(size_t value, int base)
{
	char			*s;
	int				i;
	int				len;

	len = 0;
	if (base <= 0 || base == 1 || value == 0 || base > 16)
	{
		s = ft_strdup("0");
		return (s);
	}
	len = ft_len_res(value, base);
	s = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len && value != 0)
	{
		s[i] = (value % base) + (value % base > 9 ? 'A' - 10 : '0');
		value /= (ptrdiff_t)base;
		i++;
	}
	s[i] = '\0';
	ft_zerkalo(&s);
	return (s);
}
