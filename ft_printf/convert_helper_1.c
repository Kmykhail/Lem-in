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

void	ft_strjoin_no_liks(char *s1, t_print *pr)
{
	size_t	i;
	size_t	l;
	char	*arr;

	i = 0;
	l = 0;
	if (!s1 || !pr->result)
		return ;
	arr = (char*)malloc(sizeof(char) * (ft_strlen(s1) + LEN_RES + 1));
	if (!arr)
		return ;
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	while (pr->result[l])
		arr[i++] = pr->result[l++];
	arr[i] = '\0';
	ft_strdel(&pr->result);
	pr->result = ft_strdup(arr);
	ft_strdel(&arr);
}

void	ft_sp_zr(t_print *pr, ptrdiff_t width, ptrdiff_t precis, int ch)
{
	int a;

	a = 0;
	width = ft_atoi_ll(pr->src_t);
	(width <= (LEN_ARG) && !NO_SRC && !ARG_MIN && !ch) ? JOIN(" ", pr) : 0;
	if (width > (LEN_ARG) && !ft_strchr(pr->src_t, '.') && !ch)
	{
		if (ft_strchr(pr->result, ' ') && width > (LEN_ARG + 1))
			(ft_strchr(pr->st_arg, '-')) ? (pr->result[a++] = '-') : (a++);
		while (pr->result[a])
			(RES_A_OR) ? (pr->result[a++] = '0') : (a++);
	}
	else if (ft_strchr(pr->src_t, '.'))
	{
		precis = ft_atoi_ll(ft_strchr(pr->src_t, '.') + 1);
		((W_LESS_Q_P) && precis >= LEN_ARG && !ARG_MIN) ? JOIN(" ", pr) : 0;
		((W_LESS_P) && precis <= LEN_ARG && !ARG_MIN) ? JOIN(" ", pr) : 0;
		if ((W_MORE_Q_P) && (precis > LEN_ARG) && !ARG_MIN)
		{
			(width <= LEN_ARG && precis < LEN_ARG) ? JOIN(" ", pr) : 0;
			while (pr->result[a])
				(RES_A) ? (pr->result[a++] = ' ') : (a++);
		}
	}
}

void	ft_fl_srp_3(t_print *pr, size_t a)
{
	pr->sp = 0;
	pr->sp = 0;
	while (pr->result[++a])
		pr->sp += (pr->result[a] == ' ') ? 1 : 0;
	a = 0;
	if (pr->sp > 1)
	{
		while (pr->result[a] == ' ')
			a++;
		pr->result[a - 1] = (ft_strchr(pr->src_t, 'x')) ? 'x' : 'X';
		pr->result[a - 2] = '0';
	}
	else
	{
		if (pr->sp == 1)
		{
			pr->result[0] = (ft_strchr(pr->src_t, 'x')) ? 'x' : 'X';
			ft_strjoin_no_liks("0", pr);
		}
		else
			(ft_strchr(pr->src_t, 'x')) ? (JOIN("0x", pr)) : JOIN("0X", pr);
	}
}

void	ft_fl_srp_2(t_print *pr, size_t a)
{
	if (pr->result[0] != '0' && !ft_strchr(pr->result, ' '))
	{
		if (!ft_strchr(pr->src_t, '.'))
			(ft_strchr(pr->src_t, 'x')) ? JOIN("0x", pr) : JOIN("0X", pr);
	}
	else if (pr->result[0] != '0' && ft_strchr(pr->result, ' '))
		ft_fl_srp_3(pr, a);
	else if (!ft_strchr(pr->result, ' '))
	{
		if (pr->result[0] == '0' && ft_strlen(pr->result) > 1 && !NO_SRC)
			(ft_strchr(pr->src_t, 'x')) ? (RES1) : (RES2);
		else if (ft_strchr(pr->src_t, '.'))
			(ft_strchr(pr->src_t, 'x')) ? JOIN("0x", pr) : JOIN("0X", pr);
	}
}

void	ft_fl_srp_1(t_print *pr, ptrdiff_t width, ptrdiff_t precis, int ch)
{
	int a;

	a = 0;
	if (ft_strchr(pr->src_t, 'x') || ft_strchr(pr->src_t, 'X'))
		ft_fl_srp_2(pr, a);
	else if (!ft_strchr(pr->src_t, '.') && !ft_strchr(pr->result, ' '))
		(pr->st_arg[0] != '0') ? ft_strjoin_no_liks("0", pr) : 0;
	else if (!ft_strchr(pr->src_t, '.') && ft_strchr(pr->result, ' '))
	{
		while (pr->result[++a])
			(RES_A) ? (pr->result[a] = '0') : 0;
	}
	else
	{
		width = ft_atoi_ll(pr->src_t);
		precis = ft_atoi_ll(ft_strtrim_my(ft_strchr(pr->src_t, '.'), '.'));
		(width > precis) ? JOIN("0", pr) : 0;
		(!width && !precis && pr->st_arg[0] != '0') ? JOIN("0", pr) : 0;
	}
	(ch == 15) ? ft_convert_result_flags(pr, 2, 15, 15) : 0;
}
