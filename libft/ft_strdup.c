/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 22:23:19 by kmykhail          #+#    #+#             */
/*   Updated: 2017/10/25 12:11:43 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		length;

	length = 0;
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
