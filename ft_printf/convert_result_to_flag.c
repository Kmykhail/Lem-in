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

void	ft_pl_zr(t_print *pr, ptrdiff_t len, ptrdiff_t precis, int ch)
{
	ptrdiff_t width;

	pr->cnt = 0;
	width = ft_atoi_ll(pr->src_t);
	(width <= (LEN_ARG) && !NO_SRC && !ARG_MIN && !ch) ? JOIN("+", pr) : 0;
	(width > (LEN_ARG) && !NO_SRC && !ch) ? CONVERT(pr, 1, 4, 4) : 0;
	if (ch && !ft_strchr(pr->src_t, '.') && width > (LEN_ARG))
	{
		if (width == len && ft_strchr(pr->result, '0'))
			pr->result[0] = (!ft_strchr(pr->st_arg, '-')) ? '+' : '-';
	}
	else if (ft_strchr(pr->src_t, '.'))
	{
		precis = ft_atoi_ll(ft_strtrim_my(ft_strchr(pr->src_t, '.'), '.'));
		((W_LESS_Q_P) && precis >= LEN_ARG && !ARG_MIN) ? JOIN("+", pr) : 0;
		((W_LESS_P) && precis <= LEN_ARG && !ARG_MIN) ? JOIN("+", pr) : 0;
		if ((W_MORE_P) && precis > LEN_ARG && !ft_strchr(pr->st_arg, '-'))
			while (pr->result[pr->cnt])
				(RES_CNT) ? (pr->result[pr->cnt++] = '+') : (pr->cnt++);
		else if ((W_MORE_Q_P) && precis <= LEN_ARG && !ARG_MIN)
			(width <= LEN_ARG && precis < LEN_ARG) ? JOIN("+", pr) : 0;
		while (pr->result[pr->cnt])
			(RES_CNT) ? (pr->result[pr->cnt++] = '+') : (pr->cnt++);
	}
}

void	ft_fl_zr_1(t_print *pr, size_t a)
{
	if (ft_strchr(pr->st_arg, '-') && !ft_strchr(pr->result, '0'))
	{
		pr->result[a++] = '-';
		while (pr->result[a] == ' ' || pr->result[a] == '-')
			pr->result[a++] = '0';
	}
	ft_convert_result_flags(pr, 2, 24, 24);
}

void	ft_fl_zr(t_print *pr, ptrdiff_t width, ptrdiff_t precis, int ch)
{
	pr->cnt = 0;
	if (ch == 6)
	{
		while (pr->result[pr->cnt] == ' ')
			pr->result[pr->cnt++] = '0';
		pr->cnt = 0;
		while (pr->result[pr->cnt] != 'x')
			pr->cnt++;
		pr->result[pr->cnt] = '0';
		pr->result[1] = 'x';
		return ;
	}
	(!ARG_MIN && (!RES_0)) ? ft_fl_plus_1(pr, ch, width, precis) : 0;
	if (ARG_MIN && !RES_0 && !NO_SRC)
	{
		while (pr->result[pr->cnt] == ' ' || pr->result[pr->cnt] == '-')
			pr->result[pr->cnt++] = '0';
		pr->result[0] = '-';
	}
	else if (!ARG_MIN && (ft_atoi_ll(pr->st_arg) >= 0) && !NO_SRC)
		while (pr->result[pr->cnt] == ' ')
			pr->result[pr->cnt++] = '0';
	(ch == 4) ? ft_fl_zr_1(pr, pr->cnt) : 0;
	(ch == 45) ? ft_convert_result_flags(pr, 2, 45, 45) : 0;
}

void	ft_min_sp(t_print *pr, int ch, char **arr, ptrdiff_t len)
{
	if (ch == 1)
	{
		if (!ft_strchr(pr->result, ' ') && !ft_strchr(pr->st_arg, '-'))
			ft_strjoin_no_liks(" ", pr);
		else if (ft_strchr(pr->result, ' ') && !ft_strchr(pr->st_arg, '-'))
		{
			*arr = ft_strsub(pr->result, 0, (len - 1));
			free(pr->result);
			pr->result = ft_strdup(*arr);
			ft_strjoin_no_liks(" ", pr);
			free(*arr);
		}
	}
	else
		ft_convert_result_flags(pr, 1, 1, 1);
}

void	ft_convert_result_flags(t_print *pr, int i, int c, int ch)
{
	char		*arr;
	ptrdiff_t	len;
	size_t		a;
	ptrdiff_t	width;
	ptrdiff_t	precis;

	a = 0;
	pr->cnt = 0;
	width = 0;
	precis = 0;
	(!pr->result) ? (pr->result = ft_strdup(pr->st_arg)) : 0;
	len = ft_strlen(pr->result);
	(i == 1 && c == 1) ? ft_fl_minus_2(pr, &arr, (int)len, ch) : 0;
	(i == 1 && c == 2) ? ft_fl_pl(pr, &arr, len, ch) : 0;
	(i == 1 && c == 3 && !RES_SP && !ARG_MIN) ? JOIN(" ", pr) : 0;
	(i == 1 && c == 4 && pr->result) ? ft_fl_zr(pr, width, precis, ch) : 0;
	(i == 1 && c == 5) ? ft_fl_srp_1(pr, width, precis, ch) : 0;
	(i == 2 && c == 12) ? ft_convert_result_flags(pr, 1, 2, 1) : 0;
	(i == 2 && c == 13) ? ft_min_sp(pr, ch, &arr, len) : 0;
	(i == 2 && c == 24) ? ft_pl_zr(pr, len, precis, ch) : 0;
	(i == 2 && c == 34) ? ft_sp_zr(pr, width, precis, ch) : 0;
	if (i == 2 && c == 15)
		(!ch) ? CONVERT(pr, 1, 5, 15) : CONVERT(pr, 1, 1, 15);
	else if (i == 2 && c == 45)
		(!ch) ? CONVERT(pr, 1, 4, 45) : CONVERT(pr, 1, 5, 0);
}
