/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_myq.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:11:38 by kmykhail          #+#    #+#             */
/*   Updated: 2017/11/07 16:11:41 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_myq(char *s1, char *s2)
{
	int		i;
	int		l;
	char	*qw;

	i = 0;
	l = 0;
	if ((char*)s1 == NULL || (char*)s2 == NULL)
		return (NULL);
	qw = (char*)malloc(sizeof(qw) * (ft_strlen((char*)s1)\
	+ ft_strlen((char*)s2)));
	if (!qw)
		return (NULL);
	while (((char*)s1)[i])
	{
		qw[i] = s1[i];
		i++;
	}
	while (((char*)s2)[l])
		qw[i++] = s2[l++];
	free((char*)s1);
	qw[i] = '\0';
	return (qw);
}
