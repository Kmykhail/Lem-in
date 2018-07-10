/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_last_my.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:09:30 by kmykhail          #+#    #+#             */
/*   Updated: 2017/11/06 13:09:32 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_last_my(t_list **head, t_list *new)
{
	t_list	*last;
	t_list	*fir;

	if (!head || !new)
		return ;
	fir = *head;
	last = new;
	while (fir->next != NULL)
		fir = fir->next;
	fir->next = last;
	last->next = NULL;
}
