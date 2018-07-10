/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 21:13:00 by kmykhail          #+#    #+#             */
/*   Updated: 2018/03/15 21:13:02 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_helper_parse_algo_1(t_room *room, int *i, int *ch)
{
	while (room->link && room->link[*i])
	{
		*ch += (room->link[*i] == '\n') ? 1 : 0;
		*i += 1;
	}
	if (room->link)
	{
		if (*ch > 0)
			room->lnk = ft_strsplit(room->link, '\n');
		else
		{
			room->lnk = (char**)malloc(sizeof(char*) * 2);
			room->lnk[0] = ft_strdup(room->link);
			room->lnk[1] = NULL;
		}
	}
}

void	ft_helper_algo_2(t_room *room, t_room *new, t_lem *lem)
{
	while (room)
	{
		if (room->end == 1)
			break ;
		room = room->next;
	}
	if (room)
		room->dist = 0;
	if (!room)
	{
		ft_printf("ERROR\n");
		return ;
	}
	ft_choose_way(room, lem);
	ft_move_ants(room, new, lem);
	ft_free_room(&new);
}

void	ft_write_num(t_room **room)
{
	t_room	*head;
	int		i;

	i = 0;
	head = *room;
	while (head != NULL)
	{
		head->num = i;
		head = head->next;
		i++;
	}
}

void	ft_sort_room_str(t_room **room)
{
	t_room	*head;
	t_room	*buff;
	t_room	*new;
	int		i;

	i = 0;
	head = *room;
	buff = *room;
	while (head != NULL)
	{
		if (head->str == 1 && i)
		{
			buff->next = buff->next->next;
			new = head;
			new->next = *room;
			*room = new;
			return ;
		}
		else if (head->str == 1 && !i)
			return ;
		(i) ? (buff = buff->next) : 0;
		head = head->next;
		i++;
	}
}

void	ft_sort_room_end(t_room **room)
{
	int		i;
	t_room	*head;
	t_room	*buff;

	i = 0;
	head = *room;
	buff = *room;
	while (head != NULL)
	{
		if (head->end == 1 && head->next)
		{
			buff->next = buff->next->next;
			break ;
		}
		else if (head->end == 1 && !head->next)
			return ;
		(i) ? (buff = buff->next) : 0;
		head = head->next;
		i++;
	}
	if (head)
		head->next = NULL;
	while (buff->next)
		buff = buff->next;
	buff->next = head;
}
