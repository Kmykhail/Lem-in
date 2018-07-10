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

void	ft_step_back(t_room *room, t_lem *lem)
{
	room->mark = 0;
	--lem->step;
}

void	ft_choose_way(t_room *room, t_lem *lem)
{
	int indx;

	indx = 0;
	if (room->end != 1)
	{
		lem->step++;
		room->mark = 1;
		room->dist = lem->step;
	}
	if (room->str == 1)
	{
		ft_step_back(room, lem);
		return ;
	}
	while (room->qw && room->qw[indx])
	{
		while (room->qw[indx] && (room->qw[indx]->mark \
		|| room->qw[indx]->dist <= lem->step + 1))
			++indx;
		if (!room->qw[indx])
			break ;
		ft_choose_way(room->qw[indx], lem);
		++indx;
	}
	ft_step_back(room, lem);
}

t_room	*ft_find_link(char *find, t_room *new)
{
	while (new)
	{
		if (!ft_strcmp(new->nm_c, find))
			return (new);
		new = new->next;
	}
	return (NULL);
}

void	ft_create_link(t_room *room)
{
	t_room	*new;
	int		i;
	int		c;

	new = room;
	while (room)
	{
		c = 0;
		i = 0;
		if (room->lnk)
		{
			while (room->lnk && room->lnk[i])
				i++;
			room->qw = (t_room**)malloc(sizeof(t_room) * (i + 1));
			while (c < i)
			{
				room->qw[c] = ft_find_link(room->lnk[c], new);
				c++;
			}
			room->qw[c] = NULL;
		}
		room = room->next;
	}
}

int		ft_parse_algo(t_lem *lem, t_room *room, int i)
{
	t_room	*new;
	int		ch;

	ch = 0;
	if (!room->next)
		return (0);
	ft_sort_room_str(&room);
	ft_sort_room_end(&room);
	ft_write_num(&room);
	new = room;
	while (room)
	{
		ch = 0;
		i = 0;
		ft_helper_parse_algo_1(room, &i, &ch);
		room = room->next;
	}
	room = new;
	ft_create_link(room);
	ft_helper_algo_2(room, new, lem);
	return (0);
}
