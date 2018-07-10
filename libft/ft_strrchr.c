/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 11:19:12 by kmykhail          #+#    #+#             */
/*   Updated: 2017/10/28 11:19:14 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int k;
	int check;

	i = 0;
	k = 0;
	check = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			k = i;
			check++;
		}
		i++;
	}
	if (check > 0)
		return ((char*)s + k);
	else if (check == 0 && s[i] == (char)c)
		return ((char*)&s[i]);
	return (NULL);
}
