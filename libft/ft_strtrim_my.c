/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_my.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 16:03:14 by kmykhail          #+#    #+#             */
/*   Updated: 2017/11/03 16:03:17 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		my_len(char *s, char k)
{
	int i;
	int res;
	int c;

	res = 0;
	c = 0;
	i = ft_strlen(s);
	while (s[i - 1] == k)
		i--;
	while (s[c] == k)
		c++;
	while (c < i)
	{
		res++;
		c++;
	}
	return (res);
}

char			*ft_strtrim_my(char const *s, char k)
{
	int		i;
	int		c;
	int		pov;
	char	*buff;

	if (s == NULL)
		return (NULL);
	if (!(buff = (char*)malloc(sizeof(char) * (my_len((char*)s, k)) + 1)))
		return (NULL);
	c = 0;
	pov = 0;
	i = ft_strlen(s) - 1;
	while (s[i] == k)
		i--;
	i++;
	while (s[c] == k)
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
