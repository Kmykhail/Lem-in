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
#define STRCHR_STAR	ft_strchr(pr->src_t, '*')

void	ft_un_behavior(t_print *pr, int type)
{
	pr->cnt = 0;
	if (type == 0 || type == 2)
	{
		if (!pr->b)
		{
			(JUST_MIN) ? ft_convert_result_flags(pr, 1, 1, 0) : 0;
			if (JUST_ZR)
				if (pr->result)
					while (pr->result[pr->cnt] == ' ' && pr->result[pr->cnt])
						pr->result[pr->cnt++] = '0';
		}
		(PLUS_SP) ? ft_convert_result_flags(pr, 1, 2, 0) : 0;
		(MIN_ZR) ? ft_convert_result_flags(pr, 1, 1, 0) : 0;
		(MIN_PLUS_ZR) ? ft_convert_result_flags(pr, 2, 12, 0) : 0;
		(ALL_FLAG_ON) ? ft_convert_result_flags(pr, 2, 12, 0) : 0;
		(SP_ZR_STAR) ? ft_convert_result_flags(pr, 1, 4, 0) : 0;
		(ZR_STAR) ? ft_convert_result_flags(pr, 1, 4, -4) : 0;
	}
	if (type == 3)
		(MIN_ZR_SRP) ? ft_convert_result_flags(pr, 2, 15, 0) : 0;
	if (type == 4)
		(MIN_ZR) ? ft_convert_result_flags(pr, 1, 1, 0) : 0;
	if (type == 6)
		(JUST_ZR) ? ft_convert_result_flags(pr, 1, 4, 6) : 0;
}
