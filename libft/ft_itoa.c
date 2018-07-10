/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 12:23:33 by kmykhail          #+#    #+#             */
/*   Updated: 2017/11/01 12:23:36 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*converting(char *s, int buff, int n, int sign)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		if (buff == -2147483648 && i == 0)
		{
			s[0] = 8 + '0';
			i++;
		}
		s[i] = n % 10 + '0';
		i++;
		n = n / 10;
	}
	if (sign != 1)
		s[i++] = '-';
	s[i] = '\0';
	return (s);
}

static char		*result(char *s, size_t i, int n)
{
	int	tmp;

	if (s[0] == '-' || s[0] == '+')
		i = 1;
	else
		i = 0;
	n = (int)ft_strlen(s) - 1;
	while (i < (ft_strlen(s) / 2))
	{
		tmp = s[i];
		s[i] = s[n];
		s[n] = tmp;
		i++;
		n--;
	}
	return (s);
}

static char		*collam(char *s)
{
	s = (char*)malloc(sizeof(char) * 2);
	s[0] = '0';
	s[1] = '\0';
	return (s);
}

static	int		len_str_numb(int n, int buff, char sign)
{
	int i;

	i = 0;
	while (n > 0)
	{
		if (buff == -2147483648 && i == 0)
			i++;
		n = n / 10;
		i++;
	}
	if (sign != 1)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char	*s;
	size_t	i;
	char	sign;
	int		buff;

	i = 0;
	sign = 1;
	buff = n;
	s = NULL;
	if (n == 0)
		return (collam(s));
	if (n == -2147483648)
		n = -214748364;
	if (n < 0)
	{
		sign = -1;
		n *= (-1);
	}
	s = (char*)malloc(sizeof(char) * len_str_numb(n, buff, sign) + 1);
	if (!s)
		return (NULL);
	converting(s, buff, n, sign);
	result(s, i, n);
	return (s);
}
