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
#define NO_UNI	ft_strdup_pr((char*)va_arg(ap, void*))

char	*ft_strdup_pr(const char *s1)
{
	char	*str;
	int		length;

	length = 0;
	if (!s1)
	{
		str = ft_strdup("(null)");
		return (str);
	}
	while (s1[length])
		length++;
	str = (char*)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	length = 0;
	while (s1[length])
	{
		str[length] = s1[length];
		length++;
	}
	str[length] = s1[length];
	return (str);
}

int		ft_check_mod_4(t_print *pr, va_list ap, int type, int c)
{
	if (type == 4)
	{
		((S || SRC_L)) ? (pr->wchar = (int*)va_arg(ap, void*)) : 0;
		pr->st_arg = ((S || SRC_L)) ? ft_strdup("\0") : NO_UNI;
		c++;
	}
	else if (type == 5)
	{
		if ((ft_strchr(pr->src_t, 'C') || ft_strchr(pr->src_t, 'l'))\
		&& MB_CUR_MAX == 4)
		{
			pr->utf = (unsigned int)va_arg(ap, void*);
			pr->st_arg = ft_strdup("\0");
			return (1);
		}
		pr->sym = (char)va_arg(ap, int);
		pr->st_arg = (char*)malloc(sizeof(char) * 2);
		pr->st_arg[0] = (pr->sym == 0) ? '\0' : pr->sym;
		pr->st_arg[1] = '\0';
		c++;
	}
	return (c);
}

int		ft_upper_type_str(t_print *pr, va_list ap, int type)
{
	int		len;
	int		c;

	c = 0;
	len = 0;
	pr->utf = 0;
	if (pr->src_t)
		len = (int)ft_strlen(pr->src_t);
	if ((type >= 1 && type <= 2) && (U || O) && len)
	{
		if (type == 1)
			pr->st_arg = ft_itoa_ui((uint64_t)va_arg(ap, void*));
		else if (type == 2)
			pr->st_arg = ft_itoa_base(((uint64_t)va_arg(ap, void*)), 8);
		c++;
	}
	else if ((type == 0) && D && len)
	{
		pr->st_arg = ft_itoa_an((long)va_arg(ap, void*));
		c++;
	}
	else
		c = ft_check_mod_4(pr, ap, type, c);
	return (c);
}

int		ft_check_mod(t_print *pr, va_list ap, int type, int i)
{
	if (ft_strchr(pr->src_t, '*'))
	{
		pr->star = (int)va_arg(ap, void*);
		pr->cp_star = pr->star;
	}
	if (ft_upper_type_str(pr, ap, type))
		return (0);
	if (type == 6)
	{
		pr->st_arg = P;
		while (pr->st_arg[++i])
			pr->st_arg[i] = ft_tolower(pr->st_arg[i]);
	}
	else if (ft_strchr(pr->src_t, 'z'))
	{
		if (type == 1 || type == 2)
			pr->st_arg = (type == 1) ? Z_U : Z_O;
		else
			pr->st_arg = (type == 3) ? Z_X : Z_D;
	}
	else
		ft_check_mod_3(pr, ap, type, i);
	return (0);
}
