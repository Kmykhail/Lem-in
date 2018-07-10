/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 14:24:07 by kmykhail          #+#    #+#             */
/*   Updated: 2017/11/02 14:24:09 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*buff;
	unsigned int	i;
	unsigned int	l;

	i = 0;
	l = 0;
	l = start;
	if ((char*)s == NULL)
		return (NULL);
	buff = (char*)malloc(sizeof(char) * (len + 1));
	if (!buff)
		return (NULL);
	while (i < len)
	{
		buff[i] = ((char*)s)[l];
		i++;
		l++;
	}
	buff[i] = '\0';
	return (buff);
}
