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

#define FT_CHECK_W_P ft_check_width_precision(pr, type, ap)
#define SRC		ft_strchr(pr->src_t, '.')
#define SRC_S	ft_strchr(pr->src_t, 'S')
#define SRC_L	ft_strchr(pr->src_t, 'l')

void	ft_width_char(t_print *pr)
{
	ptrdiff_t	width;

	width = (ft_strchr(pr->src_t, '*')) ? pr->star : ft_atoi_ll(pr->src_t);
	width -= (width > 0) ? 1 : 0;
	pr->result = ft_strdup(pr->st_arg);
	while (width-- > 0)
		ft_strjoin_no_liks(" ", pr);
}

void	ft_width_precision_str(t_print *pr)
{
	ptrdiff_t	width;
	int			i;

	i = 0;
	width = 0;
	ft_only_precision_str(pr);
	if (pr->wchar && !pr->result)
	{
		if (!(width = ft_atoi_ll(pr->src_t)))
		{
			pr->wchar = NULL;
			return ;
		}
	}
	ft_only_width_str(pr, i);
}

void	ft_only_precision_str(t_print *pr)
{
	ptrdiff_t	precis;
	ptrdiff_t	len;
	int			i;
	int			*arr;

	i = 0;
	if (ft_strchr(pr->src_t, '*'))
	{
		while (pr->src_t[i] != '.' && pr->src_t[i])
			i++;
		precis = (ft_isdigit(pr->src_t[i + 1])) ? PREC : pr->star;
	}
	else
		precis = PREC;
	len = (pr->wchar) ? ft_len_byte(pr->wchar) : ft_strlen(pr->st_arg);
	if (precis == 0)
	{
		pr->result = ft_strdup("\0");
		pr->wchar = NULL;
	}
	else
	{
		arr = NULL;
		ft_only_prec_str_1(pr, len, precis, arr);
	}
}

void	ft_init_char(t_print *pr, va_list ap, int type)
{
	int i;

	i = 0;
	pr->b = 1;
	pr->byte_add = 0;
	ft_check_mod(pr, ap, type, i);
	ft_check_flags(pr);
	ft_check_flags_char(pr, type);
	(SRC || ft_number(pr)) ? FT_CHECK_W_P : (pr->result = NULL);
	(pr->str_flag) ? ft_add_flags_to_result(pr, type) : 0;
	(!pr->str_flag && !pr->result) ? (pr->result = ft_strdup(pr->st_arg)) : 0;
	(!pr->result) ? pr->result = ft_strdup(pr->st_arg) : 0;
}

void	ft_char(t_print *pr, va_list ap, int type, int i)
{
	int		a;
	t_utf	*uf;

	a = 0;
	uf = malloc(sizeof(t_utf));
	ft_init_char(pr, ap, type);
	(type == 5 && !pr->utf) ? ft_print_ascii(pr) : 0;
	if (type == 5 && pr->utf)
	{
		ft_utf(pr, uf);
		while (!ft_isdigit(pr->result[a]) && pr->result[a])
			ft_putchar(pr->result[a++]);
		a = 0;
		while (uf->uf_mass[a] != '\0')
			ft_putchar(uf->uf_mass[a++]);
	}
	else if (type == 4 && (SRC_S || SRC_L))
	{
		if (ft_analys_str(pr, i, a, uf))
			return ;
	}
	else if (type != 5)
		ft_putstr(pr->result);
	pr->wchar = NULL;
	free(uf);
}
