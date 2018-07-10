/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 21:51:50 by kmykhail          #+#    #+#             */
/*   Updated: 2017/11/04 21:51:52 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *buff;

	if (!alst || !del)
		return ;
	if (!(buff = malloc(sizeof(t_list))))
		return ;
	while (*alst != NULL)
	{
		buff = (*alst)->next;
		ft_lstdelone(alst, del);
		*alst = buff;
	}
}
