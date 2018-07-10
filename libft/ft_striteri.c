/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 16:45:31 by kmykhail          #+#    #+#             */
/*   Updated: 2017/11/02 16:45:35 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (*s && (s != NULL))
	{
		f(i, s);
		s++;
		i++;
	}
}
