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

int		ft_number(t_print *pr)
{
	int i;

	i = 0;
	while (pr->src_t[i])
	{
		if (ft_isdigit(pr->src_t[i]))
			return (1);
		i++;
	}
	if (ft_strchr(pr->src_t, '*'))
		return (1);
	return (0);
}

int		ft_flags(int c)
{
	if (c == '-')
		return ('-');
	if (c == '+')
		return ('+');
	if (c == ' ')
		return (' ');
	if (c == '0')
		return ('0');
	if (c == '#')
		return ('#');
	return (0);
}

void	ft_check_mod_1(t_print *pr, va_list ap, int type, int i)
{
	while ((pr->src_t)[i])
	{
		if ((pr->src_t)[i] == 'h' && (pr->src_t)[i + 1] == 'h')
		{
			if (type == 1 || type == 2)
				pr->st_arg = (type == 1) ? HH_U : HH_O;
			else if (pr->src_t[i + 2] != 'l')
				pr->st_arg = (type == 3) ? HH_X : HH_D;
			else if (pr->src_t[i + 2] == 'l' && !type)
				pr->st_arg = L_D;
			break ;
		}
		else if ((pr->src_t)[i] == 'h' && (pr->src_t)[i + 1] != 'h')
		{
			if (type == 1 || type == 2)
				pr->st_arg = (type == 1) ? H_U : H_O;
			else
				pr->st_arg = (type == 3) ? H_X : H_D;
			break ;
		}
		i++;
	}
}

void	ft_check_mod_2(t_print *pr, va_list ap, int type, int i)
{
	while ((pr->src_t)[i])
	{
		if ((pr->src_t)[i] == 'l' && (pr->src_t)[i + 1] == 'l')
		{
			(type == 1) ? pr->st_arg = LL_U : 0;
			(type == 2) ? pr->st_arg = LL_O : 0;
			(type == 3) ? pr->st_arg = LL_X : 0;
			if (type != 1 && type != 2 && type != 3)
				pr->st_arg = ft_itoa_an((long long)va_arg(ap, void*));
			break ;
		}
		else if ((pr->src_t)[i] == 'l' && (pr->src_t)[i + 1] != 'l')
		{
			(type == 1) ? pr->st_arg = LL_U : 0;
			(type == 2) ? pr->st_arg = LL_O : 0;
			(type == 3) ? pr->st_arg = LL_X : 0;
			if (type != 1 && type != 2 && type != 3)
				pr->st_arg = ft_itoa_an((long)va_arg(ap, void*));
			break ;
		}
		i++;
	}
}

void	ft_check_mod_3(t_print *pr, va_list ap, int type, int i)
{
	if (ft_strchr(pr->src_t, 'j'))
	{
		if (type == 1 || type == 2)
			pr->st_arg = (type == 1) ? J_U : J_O;
		else
			pr->st_arg = (type == 3) ? J_X : J_D;
	}
	else if (ft_strchr(pr->src_t, 'h'))
		ft_check_mod_1(pr, ap, type, i);
	else if (ft_strchr(pr->src_t, 'l'))
		ft_check_mod_2(pr, ap, type, i);
	else if (type == 0)
		pr->st_arg = ft_itoa_an((int)va_arg(ap, void*));
	else if (type == 1)
		pr->st_arg = ft_itoa_an((unsigned int)va_arg(ap, void*));
	else if (type == 2)
		pr->st_arg = ft_itoa_base(((unsigned int)va_arg(ap, void*)), 8);
	else if (type == 3)
		pr->st_arg = ft_itoa_base(((unsigned int)va_arg(ap, void*)), 16);
}
