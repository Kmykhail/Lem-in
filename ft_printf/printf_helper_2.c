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
#define SRC_STAR ft_strchr(pr->src_t, '*')

void	ft_count_len(int *c, t_print *pr)
{
	if (pr->utf)
		*c += pr->byte_add;
	else if (!*c && !LEN_ARG && !LEN_RES && !pr->utf)
		*c += 1;
	else if (*c && !LEN_ARG && LEN_RES && !pr->utf)
		*c += 1;
	else if (*c && !ft_strlen(pr->st_arg) && !ft_strlen(pr->result) && !pr->utf)
		*c += 1;
}

void	ft_add_flags_to_result(t_print *pr, int type)
{
	if (!pr->b)
	{
		ft_un_behavior(pr, type);
		return ;
	}
	if (MINUS && !PLUS && !SP && !ZR && !SRP)
		if (pr->result && ft_strchr(pr->result, ' '))
			ft_convert_result_flags(pr, 1, 1, 0);
	(JUST_PLUS && T_2_3) ? CONVERT(pr, 1, 2, 0) : 0;
	(JUST_SP && T_2_3) ? CONVERT(pr, 1, 3, 0) : 0;
	(JUST_ZR && type != 6 && !SRC_STAR) ? CONVERT(pr, 1, 4, 0) : 0;
	(JUST_SRP && type > 1) ? CONVERT(pr, 1, 5, 0) : 0;
	(MIN_PLUS) ? CONVERT(pr, 2, 12, 0) : 0;
	(MIN_SP) ? CONVERT(pr, 2, 13, 0) : 0;
	(PLUS_ZR) ? CONVERT(pr, 2, 24, 0) : 0;
	(SP_ZR && !ft_strchr(pr->src_t, '*')) ? CONVERT(pr, 2, 34, 0) : 0;
	(MIN_SRP && type >= 2) ? CONVERT(pr, 2, 15, 0) : 0;
	(ZR_SRP && type == 3) ? CONVERT(pr, 2, 45, 0) : ft_un_behavior(pr, type);
}

void	ft_digit(t_print *pr, va_list ap, int type)
{
	int i;

	i = 0;
	pr->b = 1;
	ft_check_mod(pr, ap, type, i);
	if (type == 3 && ft_strchr(pr->src_t, 'x'))
	{
		while (pr->st_arg[i])
		{
			pr->st_arg[i] = (ft_tolower(pr->st_arg[i]));
			i++;
		}
	}
	(ft_check_flags(pr)) ? ft_del_flags(pr, type) : (pr->str_flag = NULL);
	if (ft_strchr(pr->src_t, '.') || ft_number(pr))
		ft_check_width_precision(pr, type, ap);
	if (pr->str_flag)
		ft_add_flags_to_result(pr, type);
	else if (!pr->str_flag && !pr->result)
		pr->result = ft_strdup(pr->st_arg);
	if (!pr->result)
		pr->result = ft_strdup(pr->st_arg);
	ft_putstr(pr->result);
}
