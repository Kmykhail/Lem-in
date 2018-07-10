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

int		ft_can_move(t_room *new, int ***a_ant, t_lem *lem, int sum)
{
	int	c;

	lem->help_c = 0;
	RM = -1;
	lem->val = 0;
	R_VAL = ft_short_way(new, F, &(*a_ant));
	while (new)
	{
		if (new->num == (*a_ant)[F][1])
		{
			ft_canmove_2(new, lem, &lem->val, a_ant);
			c = ft_canmove_1(new, lem, a_ant, sum);
			if (c == -1 || c == 1)
				return ((c == -1) ? -1 : 1);
		}
		new = new->next;
	}
	return (0);
}

void	ft_print_result(int ***ant, t_room *new, int end)
{
	int		i;
	int		ch;
	t_room	*tmp;

	i = 0;
	ch = 0;
	while ((*ant)[i])
	{
		if ((*ant)[i][2] == 1 || ((*ant)[i][0] != 0 && (*ant)[i][0] != 1))
		{
			tmp = new;
			while (tmp)
			{
				if (tmp->num == (*ant)[i][1])
				{
					(!ch) ? (ft_printf(ANT_1)) : (ft_printf(ANT_NEXT));
					ch = (!ch) ? 1 : ch;
					break ;
				}
				tmp = tmp->next;
			}
		}
		i++;
	}
	ft_helper_print_res(ant, i, end);
}

void	ft_sort_ant(int ***ant, int size, int i)
{
	int rm;
	int *tmp;

	rm = 0;
	if (size == 0 || size == 1)
		return ;
	while (i < size - 1)
	{
		while (i < size - 1)
		{
			rm += ((*ant)[i + 1][3] > 0 && !rm) ? 1 : 0;
			if ((*ant)[i + 1][3] == 0 && rm)
				return ;
			if ((*ant)[i][3] > (*ant)[i + 1][3])
			{
				tmp = (*ant)[i];
				(*ant)[i] = (*ant)[i + 1];
				(*ant)[i + 1] = tmp;
			}
			i++;
		}
		size--;
		i = 0;
	}
}

void	ft_move(t_room *new, t_lem *lem, t_room *room, int **ant)
{
	int c;

	c = 0;
	lem->help_f = 0;
	while (room->ant != lem->s_ant)
	{
		lem->help_f = 0;
		while (lem->help_f < lem->s_ant)
		{
			if (ant[lem->help_f][0])
			{
				if ((ft_can_move(new, &ant, lem, ft_ant_instart(ant))) == -1)
					break ;
				(ant[F][1] == room->num) ? (room->ant += 1) : (room->ant += 0);
			}
			else
				ant[lem->help_f][0] = 0;
			lem->help_f++;
		}
		ft_print_result(&ant, new, room->num);
		(!CNT) ? 0 : ft_sort_ant(&ant, lem->s_ant, 0);
		CNT++;
	}
}

int		ft_move_ants(t_room *room, t_room *new, t_lem *lem)
{
	int **arrant;
	int	i;
	int	c;

	i = 0;
	if (ft_analyze_data(new, lem, 1))
		return (ft_printf("ERROR\n") ? -1 : -1);
	arrant = (int**)malloc(sizeof(int*) * (lem->s_ant + 1));
	while (i < lem->s_ant)
	{
		c = 0;
		arrant[i] = (int*)malloc(sizeof(int) * (5));
		while (c < 4)
		{
			arrant[i][c] = (c == 0) ? 1 : 0;
			c++;
		}
		arrant[i][c] = -100;
		i++;
	}
	arrant[i] = NULL;
	ft_move(new, lem, room, arrant);
	ft_free_ant(&arrant);
	return (0);
}
