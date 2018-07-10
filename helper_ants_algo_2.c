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

void	ft_canmove(t_room *new, int ***a_ant, int f, int rm)
{
	(*a_ant)[f][0] = 2;
	(*a_ant)[f][1] = new->qw[rm]->num;
	(*a_ant)[f][2] = 1;
	(*a_ant)[f][3] = (int)new->qw[rm]->dist;
}

int		ft_canmove_1(t_room *new, t_lem *lem, int ***a_ant, int sum)
{
	if (RM < 0 || (*a_ant)[F][2] == 1)
		return ((new->num == 0) ? -1 : 1);
	else
	{
		if (new->qw[RM]->dist != new->qw[R_VAL]->dist)
		{
			if (sum < new->qw[RM]->dist && sum != 0)
				if (new->qw[RM]->dist - sum > 1)
					return (1);
		}
		ft_canmove(new, a_ant, F, RM);
		return (1);
	}
	return (0);
}

void	ft_canmove_2(t_room *new, t_lem *lem, int *val, int ***ant)
{
	while (new->qw && new->qw[CC])
	{
		if ((new->qw[CC]->dist < *val) || RM == -1)
		{
			if (!F || (ft_empty_room(*ant, new->qw[CC]) && new->qw[CC]->num))
			{
				*val = (int)new->qw[lem->help_c]->dist;
				RM = lem->help_c;
			}
		}
		lem->help_c++;
	}
}
