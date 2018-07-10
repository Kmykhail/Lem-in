/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 22:04:30 by kmykhail          #+#    #+#             */
/*   Updated: 2017/11/01 22:04:32 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		my_len(char *s)
{
	int i;
	int res;
	int c;

	res = 0;
	c = 0;
	i = ft_strlen(s);
	while (s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t')
		i--;
	while ((s[c] == ' ' || s[c] == '\n' || s[c] == '\t'))
		c++;
	while (c < i)
	{
		res++;
		c++;
	}
	return (res);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		c;
	int		pov;
	char	*buff;

	if (s == NULL)
		return (NULL);
	if ((buff = (char*)malloc(sizeof(char) * (my_len((char*)s)) + 1)) == NULL)
		return (NULL);
	c = 0;
	pov = 0;
	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	i++;
	while (s[c] == ' ' || s[c] == '\n' || s[c] == '\t')
		c++;
	while (c < i)
	{
		buff[pov] = (s[c]);
		pov++;
		c++;
	}
	buff[pov] = '\0';
	return (buff);
}
