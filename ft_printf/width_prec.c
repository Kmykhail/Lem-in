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
#define NO_DIG		!ft_isdigit(pr->src_t[0])
#define JUST_PR_N	ft_only_precision(pr, type, i, 0)
#define JUST_PR_STR	ft_only_precision_str(pr)
#define JUST_W_P_N	ft_width_precision(pr, type, ap)
#define JUST_W_P_S	ft_width_precision_str(pr)
#define FLAG_O_0	pr->str_flag[0] == '0'
#define W_P_1	ft_w_p_1(pr, width, precis, type)

void	ft_w_p_same_1(t_print *pr, ptrdiff_t precis)
{
	int i;

	i = 0;
	ft_only_width(pr);
	if (ft_strchr(pr->st_arg, '-') && precis == pr->len)
	{
		i = 0;
		pr->cnt = 0;
		pr->buff = (char*)malloc(sizeof(char) * (LEN_RES + 2));
		while (pr->result[pr->cnt] == ' ' && pr->result[pr->cnt + 1] == ' ')
		{
			pr->buff[pr->cnt] = pr->result[pr->cnt];
			pr->cnt++;
		}
		pr->buff[pr->cnt++] = '-';
		pr->buff[pr->cnt++] = '0';
		ft_w_p_same(pr, i);
	}
}

void	ft_width_precision(t_print *pr, int type, va_list ap)
{
	ptrdiff_t	width;
	ptrdiff_t	precis;
	size_t		i;
	int			st;

	st = 0;
	(ft_strchr(pr->src_t, '*')) ? ft_w_p_star(pr, ap, &width, &precis) : 0;
	if (!ft_strchr(pr->src_t, '*'))
	{
		width = ft_atoi_ll(pr->src_t);
		precis = ft_atoi_ll(ft_strchr(pr->src_t, '.') + 1);
	}
	pr->len = ft_strlen(pr->st_arg);
	if ((width <= precis && precis <= pr->len))
	{
		pr->result = ft_strdup(pr->st_arg);
		if (ft_strchr(pr->st_arg, '-') && precis == pr->len)
		{
			i = 0;
			pr->cnt = 2;
			pr->buff = ft_strdup("-0");
			ft_w_p_same(pr, i);
		}
	}
	(width >= precis && precis <= pr->len) ? ft_w_p_same_1(pr, precis) : W_P_1;
}

void	ft_only_width(t_print *pr)
{
	ptrdiff_t	width;
	ptrdiff_t	len;
	char		*arr;
	int			i;

	i = 0;
	pr->ch_star += (!pr->ch_star) ? 1 : 0;
	if (ft_strchr(pr->src_t, '*') && pr->star && pr->ch_star == 1)
		width = (STAR > 0) ? STAR : pr->star;
	else if (ft_strchr(pr->src_t, '*') && !pr->star && pr->ch_star == 1)
		width = ft_atoi_ll(ft_strchr(pr->src_t, '*') + 1);
	else
		width = ft_atoi_ll(pr->src_t);
	len = ft_strlen(pr->st_arg);
	(width < len) ? (pr->result = ft_strdup(pr->st_arg)) : 0;
	if (width >= len)
		ft_only_width_1(pr, width, len, &arr);
}

void	ft_only_precision(t_print *pr, int type, int i, int c)
{
	ptrdiff_t	precis;
	ptrdiff_t	len;

	if (ft_strchr(pr->src_t, '*'))
		precis = ft_what_precis(pr, c);
	else
		precis = PREC;
	len = (type != 6) ? ft_strlen(pr->st_arg) : (ft_strlen(pr->st_arg) - 2);
	if (type == 6 && !ft_strcmp(pr->st_arg, "0x0") && !precis)
		pr->result = ft_strdup("0x");
	else if (len == 1 && pr->st_arg[0] == '0' && precis == 0)
	{
		if (type != 2 || (type == 2 && (!pr->str_flag || FLAG_O_0)))
			pr->result = (char*)malloc(sizeof(char) * 1);
		else
		{
			pr->result = (char*)malloc(sizeof(char) * 2);
			pr->result[i++] = '0';
		}
		pr->result[i] = '\0';
	}
	else if (precis < len)
		pr->result = ft_strdup(pr->st_arg);
	else if (precis >= len)
		ft_w_p_2(pr, precis, len, type);
}

void	ft_check_width_precision(t_print *pr, int type, va_list ap)
{
	ptrdiff_t	width;
	int			i;

	i = 0;
	width = 0;
	if (!ft_strchr(pr->src_t, '.'))
	{
		if (type < 4 || type == 6)
			ft_only_width(pr);
		else
			(type == 4) ? ft_only_width_str(pr, i) : ft_width_char(pr);
	}
	else if (NO_DIG && ft_strchr(pr->src_t, '.') && pr->src_t[0] != '*')
		(type < 4 || type == 6) ? JUST_PR_N : JUST_PR_STR;
	else
		(type != 4) ? JUST_W_P_N : JUST_W_P_S;
}
