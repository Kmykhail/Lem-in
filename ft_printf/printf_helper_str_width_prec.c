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
#define LEN	ptrdiff_t len

void	ft_only_prec_str_1(t_print *pr, LEN, ptrdiff_t precis, int *arr)
{
	int i;

	i = 0;
	if (precis < len && precis > 0 && !pr->wchar)
		pr->result = ft_strsub(pr->st_arg, 0, precis);
	else if (precis < len && pr->wchar)
	{
		while (pr->wchar[i] != 0)
			i++;
		pr->cnt = 0;
		arr = (int*)malloc(sizeof(int) * i);
		while (pr->cnt < i)
		{
			arr[pr->cnt] = pr->wchar[pr->cnt];
			pr->cnt++;
		}
		arr[pr->cnt] = 0;
		pr->cnt--;
		while (precis < (len = ft_len_byte(arr)))
			arr[pr->cnt--] = 0;
		pr->wchar = arr;
		free(arr);
	}
}

void	ft_check_flags_char(t_print *pr, int type)
{
	if (pr->str_flag && (type == 4 || type == 5))
	{
		if (!ft_strchr(pr->str_flag, '-') && !ft_strchr(pr->str_flag, '0'))
			ft_strdel(&pr->str_flag);
		else if (!ft_strchr(pr->str_flag, '-') && ft_strchr(pr->str_flag, '0'))
		{
			ft_strdel(&pr->str_flag);
			pr->str_flag = ft_strdup("0");
		}
		else if (ft_strchr(pr->str_flag, '-') && !ft_strchr(pr->str_flag, '0'))
		{
			ft_strdel(&pr->str_flag);
			pr->str_flag = ft_strdup("-");
		}
		else if (ft_strchr(pr->str_flag, '-') && ft_strchr(pr->str_flag, '0'))
		{
			ft_strdel(&pr->str_flag);
			pr->str_flag = ft_strdup("-0");
		}
		ft_del_flags(pr, type);
	}
}

int		ft_analys_str(t_print *pr, int i, int a, t_utf *uf)
{
	if (!pr->wchar)
	{
		(ft_strchr(pr->src_t, '.')) ? ft_putstr(pr->result) : 0;
		if (!ft_strchr(pr->src_t, '.'))
		{
			ft_putstr("(null)");
			pr->byte_add = 6;
		}
		return (1);
	}
	if (pr->str_flag)
		(!ft_strchr(pr->str_flag, '-')) ? (ft_putstr(pr->result)) : 0;
	else
		ft_putstr(pr->result);
	while (pr->wchar[a] != 0)
	{
		i = 0;
		pr->utf = pr->wchar[a++];
		ft_utf(pr, uf);
		while (uf->uf_mass[i] != '\0')
			ft_putchar(uf->uf_mass[i++]);
	}
	if (pr->str_flag)
		(ft_strchr(pr->str_flag, '-')) ? ft_putstr(pr->result) : 0;
	return (0);
}

void	ft_print_ascii(t_print *pr)
{
	if (pr->st_arg[0] == '\0' && ft_strchr(pr->src_t, '*'))
	{
		if (pr->str_flag)
		{
			if (ft_strchr(pr->str_flag, '-'))
			{
				write(1, &pr->sym, 1);
				ft_putstr(pr->result);
			}
			else if (pr->str_flag[0] == '0')
			{
				write(1, &pr->sym, 1);
				ft_putstr(pr->result);
			}
		}
		else
			ft_putchar(pr->sym);
	}
	else
	{
		ft_putstr(pr->result);
		(pr->st_arg[0] == '\0') ? ft_putchar(pr->sym) : 0;
	}
}

void	ft_only_width_str(t_print *pr, int i)
{
	ptrdiff_t	width;
	ptrdiff_t	len;

	width = (ft_strchr(pr->src_t, '*')) ? pr->star : ft_atoi_ll(pr->src_t);
	if (pr->wchar)
		len = ft_len_byte(pr->wchar);
	else
		len = (!pr->result) ? ft_strlen(pr->st_arg) : ft_strlen(pr->result);
	if (width > len)
	{
		width -= len;
		if (!pr->result)
		{
			pr->result = (char*)malloc(sizeof(char) * (width + 1));
			while (width-- > 0)
				pr->result[i++] = ' ';
			pr->result[i] = '\0';
			ft_strcat(pr->result, pr->st_arg);
		}
		else
			while (width-- > 0)
				ft_strjoin_no_liks(" ", pr);
	}
	else if (width <= len)
		(!pr->result) ? (pr->result = ft_strdup(pr->st_arg)) : 0;
}
