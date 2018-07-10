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

int		ft_check_flags_helper(t_print *pr, int cnt, int n, int i)
{
	int c;

	c = 0;
	if (ft_strchr(pr->src_t, '*') && pr->star < 0)
	{
		cnt++;
		pr->star *= -1;
	}
	pr->str_flag = (char*)malloc(sizeof(char) * (cnt + 1));
	i = 0;
	c = 0;
	while (pr->src_t[i])
	{
		if (ft_flags(pr->src_t[i]) && c < cnt)
			pr->str_flag[c++] = pr->src_t[i];
		i++;
	}
	if (ft_strchr(pr->src_t, '*') && !pr->star)
		pr->str_flag[c++] = (n) ? ' ' : '0';
	(ft_strchr(pr->src_t, '*') && pr->star < 0) ? (pr->str_flag[c++] = '-') : 0;
	if (ft_strchr(pr->src_t, '*') && !pr->star)
		pr->str_flag[c++] = (n) ? ' ' : '0';
	pr->str_flag[c] = '\0';
	return (c);
}

int		ft_check_flags(t_print *pr)
{
	int i;
	int c;
	int cnt;
	int	n;

	i = 0;
	cnt = 0;
	c = 0;
	n = 0;
	while (pr->src_t[i])
	{
		cnt += (ft_flags(pr->src_t[i])) ? 1 : 0;
		if (pr->src_t[i] == '*' && !pr->star && ft_isdigit(pr->src_t[i + 1]))
		{
			n = i + 1;
			cnt++;
		}
		cnt -= (i && pr->src_t[i] == '0' && (FLAG || SRC_T)) ? 1 : 0;
		i++;
	}
	if (!cnt)
		return ((ft_check_flags_1(pr)) ? 1 : 0);
	c = ft_check_flags_helper(pr, cnt, n, i);
	return (c);
}

void	ft_del_concrete_sym(char **arr, char sym)
{
	int		i;
	int		cnt;
	char	*str;

	i = 0;
	cnt = 0;
	if (!*arr || !sym)
		return ;
	while ((*arr)[i])
		cnt += ((*arr)[i++] == sym) ? 1 : 0;
	if (!cnt)
		return ;
	str = (char*)malloc(sizeof(char) * ((i - cnt) + 1));
	i = 0;
	cnt = 0;
	while ((*arr)[i])
	{
		((*arr)[i] != sym) ? (str[cnt++] = (*arr)[i]) : 0;
		i++;
	}
	str[cnt] = '\0';
	free(*arr);
	*arr = ft_strdup(str);
	free(str);
}

void	ft_del_flags_helper(t_print *pr, int type, char **buff, int i)
{
	int cnt;

	cnt = 0;
	while (pr->src_t[i])
	{
		if (i && pr->src_t[i] == '0' && ft_isdigit(pr->src_t[i - 1]))
			(*buff)[cnt++] = pr->src_t[i];
		(!ft_flags(pr->src_t[i])) ? ((*buff)[cnt++] = pr->src_t[i]) : 0;
		i++;
	}
	(*buff)[cnt] = '\0';
	if (type == 1)
	{
		if (ft_strchr(pr->src_t, '+'))
		{
			ft_del_concrete_sym(&(*buff), '+');
			ft_del_concrete_sym(&pr->str_flag, '+');
		}
		if (ft_strchr(pr->src_t, ' '))
		{
			ft_del_concrete_sym(&(*buff), ' ');
			ft_del_concrete_sym(&pr->str_flag, ' ');
		}
	}
}

void	ft_del_flags(t_print *pr, int type)
{
	char	*buff;
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (pr->src_t[i])
	{
		cnt += (!ft_flags((pr->src_t[i]))) ? 1 : 0;
		if (i && pr->src_t[i] == '0' && ft_isdigit(pr->src_t[i - 1]))
			cnt++;
		i++;
	}
	if (!cnt)
		return ;
	buff = (char*)malloc(sizeof(char) * (cnt + 1));
	i = 0;
	ft_del_flags_helper(pr, type, &buff, i);
	ft_strdel(&pr->src_t);
	pr->src_t = ft_strdup(buff);
	free(buff);
}
