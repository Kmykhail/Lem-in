/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 15:53:14 by kmykhail          #+#    #+#             */
/*   Updated: 2017/11/04 15:53:16 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	*ft_func(t_list **head)
{
	t_list	*buff;
	t_list	*top;

	buff = malloc(sizeof(t_list));
	top = *head;
	while (top != NULL)
	{
		buff = top->next;
		free(top);
		top = buff;
	}
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*head;
	t_list	*copy;

	if (!lst || !f)
		return (NULL);
	new = (*f)(lst);
	if (!new)
		return (NULL);
	copy = new;
	head = lst->next;
	while (head != NULL)
	{
		new->next = (*f)(head);
		new = new->next;
		if (!new)
		{
			ft_func(&lst);
			return (NULL);
		}
		head = head->next;
	}
	return (copy);
}
