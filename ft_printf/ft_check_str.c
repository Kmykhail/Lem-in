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
#define FLAG_SRC	!ft_flags(pr->src_t[i])

void	ft_no_type_1(t_print *pr, int c, int a)
{
	ptrdiff_t width;

	width = ft_atoi_ll(pr->src_t);
	if (width > 1 && c)
	{
		a = 0;
		width--;
		pr->result = (char*)malloc(sizeof(char) * (width + 1));
		while (width-- > 0)
			pr->result[a++] = ' ';
		pr->result[a] = '\0';
		ft_strcat(pr->result, pr->st_arg);
	}
}

int		ft_no_type(t_print *pr)
{
	int	a;
	int	d;
	int	c;

	a = 0;
	d = 0;
	c = 0;
	while (pr->src_t[a])
	{
		if (ft_isdigit(pr->src_t[a]) && a == 0)
			while (ft_isdigit(pr->src_t[++a]))
				d++;
		if (pr->src_t[a] >= 33 && pr->src_t[a] <= 126)
		{
			c++;
			break ;
		}
		a++;
	}
	if (!a)
		return (0);
	ft_no_type_1(pr, c, a);
	return (0);
}

void	ft_last_check_str_1(t_print *pr, int i, int c)
{
	ft_del_concrete_sym(&pr->st_arg, '.');
	while (pr->st_arg[i++])
		c += (!ft_isdigit(pr->st_arg[i])) ? 1 : 0;
	i = 0;
	pr->buff = (char*)malloc(sizeof(char) * (c + 1));
	c = 0;
	while (pr->st_arg[i])
	{
		(!ft_isdigit(pr->st_arg[i])) ? (pr->buff[c++] = pr->st_arg[i]) : 0;
		i++;
	}
	pr->buff[c] = '\0';
	ft_strdel(&pr->st_arg);
	pr->st_arg = ft_strdup(pr->buff);
	ft_strdel(&pr->buff);
	if (!ft_strchr(pr->st_arg, '.'))
		(!pr->b) ? ft_no_type(pr) : ft_only_width(pr);
}

int		ft_analyse_last_check(t_print *pr, int type, int i, int c)
{
	while (pr->src_t[i])
	{
		while (ft_flags(pr->src_t[i]))
			i++;
		while (ft_isdigit(pr->src_t[i]))
			i++;
		if (FLAG_SRC && !ft_isdigit(pr->src_t[i]) && pr->src_t[i])
			pr->st_arg = ft_strdup(&pr->src_t[i]);
		break ;
	}
	i = 0;
	(ft_check_flags(pr)) ? ft_del_flags(pr, type) : (pr->str_flag = NULL);
	if (ft_len_zero(pr))
		return (0);
	if (!ft_strchr(pr->st_arg, '.'))
		(!pr->b) ? ft_no_type(pr) : ft_only_width(pr);
	else if (ft_strchr(pr->st_arg, '.'))
		ft_last_check_str_1(pr, i, c);
	if (pr->str_flag)
		ft_add_flags_to_result(pr, type);
	else if (!pr->str_flag && !pr->result)
		pr->result = ft_strdup(pr->st_arg);
	(!pr->result) ? (pr->result = ft_strdup(pr->st_arg)) : 0;
	ft_putstr(pr->result);
	return (1);
}

int		ft_last_check_str(t_print *pr, char *s, int *n, int type)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	if (type == 5)
		return (0);
	if (type == 4)
	{
		while (s[i] != 's' && s[i] != 'S')
			i++;
		c = i + 1;
		while (s[c])
			ft_putchar(s[c++]);
		*n += c - i - 1;
		return (0);
	}
	pr->src_t = ft_strdup(s);
	(ft_strchr(pr->src_t, '+')) ? ft_del_concrete_sym(&pr->src_t, '+') : 0;
	(ft_strchr(pr->src_t, '#')) ? ft_del_concrete_sym(&pr->src_t, '#') : 0;
	if (ft_analyse_last_check(pr, type, i, c))
		*n += ft_strlen(pr->result);
	return (0);
}
