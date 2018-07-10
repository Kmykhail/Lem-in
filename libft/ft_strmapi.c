/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:22:50 by kmykhail          #+#    #+#             */
/*   Updated: 2017/11/02 15:22:52 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*buff;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	buff = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!buff)
		return (NULL);
	while (s[i])
	{
		buff[i] = f((unsigned int)i, s[i]);
		i++;
	}
	buff[i] = '\0';
	return (buff);
}
