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

void	ft_init_var(t_lem *lem, t_room *room)
{
	lem->step = 0;
	lem->s_ant = 0;
	lem->coor_st_r = -1;
	lem->coor_end_r = -1;
	lem->stor = NULL;
	lem->error = 0;
	lem->itr = 0;
	lem->st_end_r = 0;
	lem->str = 0;
	lem->stop = 0;
	lem->end = 0;
	lem->coors = 0;
	lem->indx = 0;
	lem->line = NULL;
	lem->rooms = NULL;
	lem->sml = NULL;
	room->cr_y = -1;
	room->cr_x = -1;
	room->nm_c = NULL;
	room->next = NULL;
	room->link = NULL;
	room->lnk = NULL;
	room->qw = NULL;
	room->num = 0;
	room->dist = 2147483647;
}

void	ft_free_struct(t_lem **lem)
{
	int i;
	int c;

	i = 0;
	c = 0;
	((*lem)->stor) ? ft_strdel(&(*lem)->stor) : 0;
	free((*lem)->coors);
	while ((*lem)->sml && (*lem)->sml[i])
		ft_strdel(&(*lem)->sml[i++]);
	free((*lem)->sml);
	i = 0;
	while ((*lem)->rooms && (*lem)->rooms[i])
		ft_strdel(&(*lem)->rooms[i++]);
	free((*lem)->rooms);
	ft_strdel(&(*lem)->line);
	free(*lem);
	*lem = NULL;
}

int		main(void)
{
	t_lem	*lem;
	t_room	*room;

	lem = malloc(sizeof(t_lem));
	room = malloc(sizeof(t_room));
	ft_init_var(lem, room);
	lem->ires = 0;
	if (ft_valid(lem, room) < 0)
	{
		free(lem);
		free(room);
		ft_printf("ERROR\n");
		return (0);
	}
	ft_free_struct(&lem);
	return (0);
}
