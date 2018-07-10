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

void	ft_fl_pl(t_print *pr, char **arr, ptrdiff_t len, int ch)
{
	int a;

	a = 0;
	if (ft_strchr(pr->result, ' ') && !ft_strchr(pr->st_arg, '-'))
	{
		while (pr->result[a++])
			(RES_A) ? (pr->result[a] = '+') : 0;
	}
	if (!ft_strchr(pr->result, ' ') && !ft_strchr(pr->st_arg, '-'))
	{
		*arr = (char*)malloc(sizeof(char) * (len + 2));
		(*arr)[a++] = '+';
		while (pr->result[pr->cnt])
			(*arr)[a++] = pr->result[pr->cnt++];
		(*arr)[a] = '\0';
		free(pr->result);
		pr->result = ft_strdup(*arr);
		free(*arr);
	}
	(ch == 1) ? ft_convert_result_flags(pr, 1, ch, 0) : 0;
}

void	ft_fl_minus_2(t_print *pr, char **arr, int len, int ch)
{
	int a;

	a = 0;
	if (!pr->b)
	{
		while (pr->result[++a])
			if (pr->result[a] != ' ')
				break ;
		pr->result[0] = pr->result[a];
		pr->result[a] = ' ';
		return ;
	}
	*arr = (char*)malloc(sizeof(char) * (len + 1));
	while (pr->result[++a])
		(pr->result[a] != ' ') ? ((*arr)[pr->cnt++] = pr->result[a]) : 0;
	a = 0;
	while (pr->result[a] == ' ' && pr->result[a])
		(*arr)[pr->cnt++] = pr->result[a++];
	(*arr)[pr->cnt] = '\0';
	ft_strdel(&pr->result);
	pr->result = ft_strdup(*arr);
	ft_strdel(&(*arr));
	if (ch == 1)
		ft_convert_result_flags(pr, 2, 13, 1);
}

void	ft_fl_plus_1(t_print *pr, int ch, ptrdiff_t width, ptrdiff_t precis)
{
	int a;

	a = 0;
	if (ft_strchr(pr->src_t, '.'))
	{
		width = ft_atoi_ll(pr->src_t);
		precis = ft_atoi_ll(ft_strtrim_my(ft_strchr(pr->src_t, '.'), '.'));
		if (width > LEN_ARG && precis <= LEN_ARG)
		{
			while (pr->result[a] == ' ' && pr->result[a])
				a++;
			if ((a == LEN_RES && !pr->st_arg[0]) || ch == -4)
			{
				a = 0;
				while (pr->result[a] == ' ')
					pr->result[a++] = '0';
			}
		}
		else
			while (pr->result[a] == ' ')
				pr->result[a++] = '0';
	}
	else
		while (pr->result[a] == ' ')
			pr->result[a++] = '0';
}
