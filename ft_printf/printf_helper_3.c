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

int		ft_pre_check_str(char *str, int *c, t_print *pr)
{
	int	i;
	int	ch;
	int	q;

	i = 0;
	ch = 0;
	q = 0;
	while ((str)[i])
	{
		if (str[i] != '%' && pr->it)
			break ;
		if ((str)[i] == '%' && (str)[i + 1] != '%' && (str)[i + 1] != '\0')
			break ;
		else if ((str)[i] == '%' && (str)[i + 1] == '%')
			i++;
		else if ((str)[i] == '%' && !(str)[i + 1])
		{
			q = -1;
			break ;
		}
		ft_putchar((str)[i++]);
		ch++;
	}
	*c += ch;
	return ((q < 0) ? -1 : i);
}

int		ft_variant_str(char **str, va_list ap, int *c, t_print *pr)
{
	size_t	cnt;
	int		i;

	cnt = pr->ct;
	i = 0;
	if ((T_C || T_S))
	{
		pr->src_t = ft_strsub(*str, (pr->it + 1), (cnt - pr->it));
		(T_S) ? (ft_char(pr, ap, 4, i)) : (ft_char(pr, ap, 5, i));
		*c += ft_strlen(pr->result);
		pr->type += (T_S) ? 4 : 5;
		if (pr->type == 5)
			ft_count_len(&(*c), pr);
		else if (pr->type == 4)
			*c += pr->byte_add;
		return (1);
	}
	if ((*str)[cnt] == 'Z' && ft_strchr(*str, 's'))
	{
		ft_putchar('Z');
		*c += 1;
		pr->b = 1;
		return (1);
	}
	return (0);
}

int		ft_variant_nb(char **str, va_list ap, int *c, t_print *pr)
{
	size_t cnt;

	cnt = pr->ct;
	if ((T_D || T_U || T_O || T_X) && Z)
		return (1);
	if (T_D || (*str)[cnt] == 'i' || T_U || T_O || T_X)
	{
		pr->src_t = ft_strsub(*str, (pr->it + 1), (cnt - pr->it));
		(T_D || (*str)[cnt] == 'i') ? ft_digit(pr, ap, 0) : 0;
		(T_U) ? (ft_digit(pr, ap, 1)) : 0;
		(T_O) ? (ft_digit(pr, ap, 2)) : 0;
		(T_X) ? ft_digit(pr, ap, 3) : 0;
		*c += ft_strlen(pr->result);
		return (1);
	}
	else if (ft_isprint((*str)[cnt]) && ((*str)[cnt] == 'p'))
	{
		pr->src_t = ft_strsub(*str, (pr->it + 1), (cnt - pr->it));
		ft_pointer(pr, ap, 6);
		*c += ft_strlen(pr->result);
		return (1);
	}
	return (0);
}

int		ft_variant_text(char **str, size_t cnt, int *c, t_print *pr)
{
	if ((*str)[cnt + 1] != '\0' && pr->b)
		pr->it = (int)cnt + 1;
	else
	{
		if (!*c || !pr->b)
			ft_last_check_str(pr, &(*str)[pr->it + 1], &(*c), pr->type);
		return (pr->it);
	}
	return (0);
}

int		ft_print_text(char **str, t_print *pr, int *c)
{
	int k;

	k = 0;
	if ((*str)[pr->it - 1] == '\0')
		return (1);
	else if ((*str)[pr->it] == '%' && (*str)[pr->it] != '0')
		k++;
	else
	{
		ft_putchar((*str)[pr->it++]);
		*c += 1;
	}
	return (0);
}
