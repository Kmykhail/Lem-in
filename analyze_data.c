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

void	ft_display_data(t_lem *lem)
{
	int i;

	i = 0;
	ft_putstr(lem->stor);
	ft_printf("\n\n");
}

int		ft_analyze_data(t_room *room, t_lem *lem, int status)
{
	int i;

	i = 0;
	if ((!status && (lem->str && !lem->end)) || !status)
		return (ft_printf("ERROR\n"));
	if (status)
	{
		if (room->dist == MAX_ROOM || !lem->s_ant)
			return (1);
		while (room->qw && room->qw[i])
		{
			if (room->qw[i]->dist < MAX_ROOM)
			{
				ft_display_data(lem);
				return (0);
			}
			i++;
		}
		return (1);
	}
	return (0);
}
