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

void	ft_list_null(t_print *pr, int *c, size_t *cnt)
{
	*c = 0;
	*cnt = 0;
	pr->sym = '\0';
	pr->st_arg = NULL;
	pr->result = NULL;
	pr->str_flag = NULL;
	pr->src_t = NULL;
	pr->buff = NULL;
	pr->b = 0;
	pr->utf = 0;
	pr->star = 0;
	pr->type = 0;
	pr->cp_star = 0;
	pr->prec = 0;
	pr->ch_star = 0;
	pr->ct = 0;
	pr->it = 0;
	pr->wchar = NULL;
}

void	ft_list_free(t_print *pr)
{
	int i;

	i = 0;
	if (pr)
	{
		pr->b = 0;
		pr->byte_add = 0;
		pr->cnt = 0;
		(pr->result) ? (ft_strdel(&pr->result)) : 0;
		(pr->st_arg) ? (ft_strdel(&pr->st_arg)) : 0;
		(pr->src_t) ? (ft_strdel(&pr->src_t)) : 0;
		(pr->str_flag) ? (ft_strdel(&pr->str_flag)) : 0;
		(pr->buff) ? (ft_strdel(&pr->buff)) : 0;
		(pr->wchar) ? (pr->wchar = NULL) : 0;
	}
}

int		ft_all_type(t_print *pr, va_list ap, char **str, int *c)
{
	int cnt;

	cnt = pr->it;
	pr->type = 0;
	while ((*str)[cnt])
	{
		pr->ct = cnt;
		if ((*str)[cnt] == '%' && (*str)[cnt + 1] == '%')
		{
			ft_pre_check_str(&(*str)[cnt++], &(*c), pr);
			pr->it++;
			break ;
		}
		if (ft_variant_nb(&(*str), ap, &(*c), pr))
			return (cnt);
		if (ft_variant_str(&(*str), ap, &(*c), pr))
			return (cnt);
		ft_list_free(pr);
		cnt++;
	}
	return (cnt);
}

size_t	ft_check_per(va_list ap, char *str)
{
	size_t	cnt;
	int		c;
	t_print	*pr;

	pr = malloc(sizeof(t_print));
	ft_list_null(pr, &c, &cnt);
	pr->it = CHECK_STR(str, &c, pr);
	if (c < 0 || pr->it < 0)
		return (c);
	while (str[pr->it])
	{
		if (str[pr->it] == '%' && str[pr->it + 1] != '\0')
		{
			cnt = ft_all_type(pr, ap, &str, &c);
			if ((ft_variant_text(&str, cnt, &c, pr)))
				break ;
		}
		if ((ft_print_text(&str, pr, &c)))
			break ;
	}
	ft_list_free(pr);
	free(pr);
	return (c);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	if (format)
	{
		va_start(ap, format);
		if (ft_strchr(format, '%'))
			i = (int)ft_check_per(ap, (char*)format);
		else
		{
			i = (int)ft_strlen(format);
			ft_putstr(format);
		}
	}
	format = NULL;
	va_end(ap);
	return (i);
}
