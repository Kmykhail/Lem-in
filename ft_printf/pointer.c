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

void	ft_pointer_1(t_print *pr, va_list ap, int type)
{
	if (pr->str_flag)
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
	if (ft_strchr(pr->src_t, '.') || ft_number(pr))
		ft_check_width_precision(pr, type, ap);
	else if (ft_strchr(pr->src_t, '.'))
		ft_only_precision(pr, type, 0, 0);
}

void	ft_pointer(t_print *pr, va_list ap, int type)
{
	char	*arr;
	int		i;
	int		c;

	pr->b = 1;
	i = 0;
	c = 2;
	ft_check_mod(pr, ap, type, i);
	ft_check_flags(pr);
	arr = (char*)malloc(sizeof(char) * (ft_strlen(pr->st_arg) + 3));
	arr[0] = '0';
	arr[1] = 'x';
	while (pr->st_arg[i])
		arr[c++] = pr->st_arg[i++];
	arr[c] = '\0';
	ft_strdel(&pr->st_arg);
	pr->st_arg = ft_strdup(arr);
	ft_strdel(&arr);
	ft_pointer_1(pr, ap, type);
	(pr->str_flag) ? ft_add_flags_to_result(pr, type) : 0;
	(!pr->result) ? (pr->result = ft_strdup(pr->st_arg)) : 0;
	ft_putstr(pr->result);
}
