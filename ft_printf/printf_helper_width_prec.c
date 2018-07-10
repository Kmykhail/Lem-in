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

void	ft_w_p_2(t_print *pr, ptrdiff_t precis, ptrdiff_t len, int type)
{
	char	*buff;
	int		i;

	i = 0;
	ft_w_p_3(pr, &buff, len, precis);
	if (!ft_strchr(pr->st_arg, '-'))
	{
		ft_strcat(buff, pr->result);
		ft_strcat(buff, pr->st_arg);
	}
	ft_strdel(&pr->result);
	pr->result = ft_strdup(buff);
	if (type == 6 && pr->result[1] != 'x')
	{
		i = 0;
		while (pr->result[i] != 'x')
			i++;
		pr->result[i] = pr->result[1];
		pr->result[1] = 'x';
	}
	free(buff);
}

void	ft_w_p_1(t_print *pr, ptrdiff_t width, ptrdiff_t precis, int type)
{
	int i;

	i = 0;
	if (width <= precis && precis >= pr->len)
		ft_only_precision(pr, type, i, 1);
	else if (width > precis && precis > pr->len)
	{
		width -= (ft_strchr(pr->st_arg, '-')) ? 1 : 0;
		ft_only_precision(pr, type, i, 0);
		if (width > precis)
		{
			width -= precis;
			while (width-- > 0)
				ft_strjoin_no_liks(" ", pr);
		}
	}
}

void	ft_w_p_same(t_print *pr, size_t i)
{
	while (pr->result[i++])
		(ft_isdigit(pr->result[i])) ? (pr->buff[pr->cnt++] = pr->result[i]) : 0;
	pr->buff[pr->cnt] = '\0';
	ft_strdel(&pr->result);
	pr->result = ft_strdup(pr->buff);
	ft_strdel(&pr->buff);
}

void	ft_star_iswidth(t_print *pr, int i, ptrdiff_t *w, ptrdiff_t *p)
{
	while (pr->src_t[i] != '*' && pr->src_t)
		i++;
	if (pr->src_t[i + 1] == '.')
	{
		*w = pr->star;
		*p = ft_atoi_ll(ft_strchr(pr->src_t, '.') + 1);
		pr->ch_star = 1;
	}
	else if (i && pr->src_t[i - 1] == '.')
	{
		*p = (pr->cp_star < 0) ? 0 : pr->star;
		*w = ft_atoi_ll(pr->src_t);
		pr->ch_star = 2;
	}
}

void	ft_w_p_star(t_print *pr, va_list ap, ptrdiff_t *w, ptrdiff_t *p)
{
	int i;
	int	st;

	i = 0;
	st = 0;
	while (pr->src_t[i])
		st += (pr->src_t[i++] == '*') ? 1 : 0;
	i = 0;
	if (st == 1)
		ft_star_iswidth(pr, i, &(*w), &(*p));
	else if (st > 1)
	{
		while (pr->src_t[i] != '*' && pr->src_t)
			i++;
		*w = (pr->src_t[i + 1] == '.') ? pr->star : 0;
		*p = (int)va_arg(ap, void*);
		i = (int)*p;
		*p = (ft_atoi_ll(pr->st_arg));
		pr->prec = (int)*p;
		pr->ch_star = 2;
		ft_strdel(&pr->st_arg);
		pr->st_arg = ft_itoa_an(i);
	}
}
