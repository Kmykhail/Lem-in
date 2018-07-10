/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:23:41 by kmykhail          #+#    #+#             */
/*   Updated: 2017/11/02 15:23:47 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*buff;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	buff = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!buff)
		return (NULL);
	while (s[i])
	{
		buff[i] = f(s[i]);
		i++;
	}
	buff[i] = '\0';
	return (buff);
}
