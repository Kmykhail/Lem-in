/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount_my.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:11:38 by kmykhail          #+#    #+#             */
/*   Updated: 2017/11/07 16:11:41 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstcount_my(t_list *head)
{
	int		i;
	t_list	*current;

	if (!head)
		return (0);
	i = 0;
	current = head;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}
