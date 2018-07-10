/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 14:02:42 by exam              #+#    #+#             */
/*   Updated: 2018/01/19 15:00:22 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_flags_1(t_print *pr)
{
	if (ft_strchr(pr->src_t, '*') && pr->star < 0)
	{
		pr->str_flag = ft_strdup("-");
		pr->star *= -1;
		return (1);
	}
	return (0);
}

int		ft_len_zero(t_print *pr)
{
	int i;

	i = 0;
	if (!pr->st_arg || pr->st_arg)
	{
		if (!pr->st_arg)
			return (1);
		if (pr->st_arg)
		{
			if (NO_H || NO_L || NO_Z || NO_J)
			{
				if (YES_Z && ft_strchr(pr->st_arg, '%'))
				{
					ft_del_concrete_sym(&pr->st_arg, 'h');
					ft_del_concrete_sym(&pr->st_arg, '%');
				}
				else if (YES_Z && !ft_strchr(pr->st_arg, '%'))
					ft_del_concrete_sym(&pr->st_arg, 'h');
				else
					return (1);
			}
		}
	}
	return (0);
}

void	ft_w_p_3(t_print *pr, char **buff, ptrdiff_t l, ptrdiff_t p)
{
	int i;

	i = 0;
	p -= l;
	pr->result = (char*)malloc(sizeof(char) * (p + 1));
	if (ft_strchr(pr->st_arg, '-'))
		while (p-- >= 0)
			pr->result[i++] = '0';
	else
		while (p-- > 0)
			pr->result[i++] = '0';
	pr->result[i] = '\0';
	l = ft_strlen(pr->result) + ft_strlen(pr->st_arg);
	*buff = (char*)malloc(sizeof(char) * (l + 1));
	if (ft_strchr(pr->st_arg, '-'))
	{
		(*buff)[0] = '-';
		(*buff)[1] = '\0';
		ft_strcat(*buff, pr->result);
		ft_strcat(*buff, pr->st_arg + 1);
	}
}

void	ft_only_width_1(t_print *pr, ptrdiff_t width, ptrdiff_t len, char **arr)
{
	int i;

	i = 0;
	width -= (pr->st_arg && !len) ? (len + 1) : len;
	pr->result = (char*)malloc(sizeof(char) * (width + 1));
	while (width > 0)
	{
		pr->result[i++] = ' ';
		width--;
	}
	pr->result[i] = '\0';
	if (pr->st_arg[0] == '0' && pr->st_arg[1] == 'x')
		ft_strcat(pr->result, pr->st_arg);
	else if (pr->st_arg[0] == '0' && ft_strchr(pr->src_t, '.'))
		ft_strcat(pr->result, " ");
	else
	{
		*arr = ft_strjoin(pr->result, pr->st_arg);
		ft_strdel(&pr->result);
		pr->result = ft_strdup(*arr);
		ft_strdel(&(*arr));
	}
}

int		ft_what_precis(t_print *pr, int c)
{
	if (c > 0)
		return ((pr->prec > 0) ? pr->prec : PREC);
	else if (!c && pr->cp_star < 0)
		return (0);
	else if (!c && pr->star >= 0)
		return (pr->star);
	return (0);
}
