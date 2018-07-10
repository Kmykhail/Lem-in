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

int		ft_ant_instart(int **arrant)
{
	int i;
	int sum;

	i = 0;
	sum = 0;
	while (arrant[i])
	{
		sum += (arrant[i][0] == 1) ? 1 : 0;
		i++;
	}
	return (sum);
}

void	ft_helper_print_res(int ***ant, int i, int end)
{
	i = 0;
	while ((*ant)[i])
	{
		(*ant)[i][0] = ((*ant)[i][1] == end) ? 0 : (*ant)[i][0];
		(*ant)[i][2] = 0;
		if ((*ant)[i][1] == 0)
			break ;
		i++;
	}
	ft_printf("\n");
}

void	ft_free_ant(int ***ant)
{
	int	i;

	i = 0;
	while ((*ant)[i])
		free((*ant)[i++]);
	free((*ant));
	(*ant) = NULL;
}

int		ft_empty_room(int **a_ant, t_room *new)
{
	int	i;

	i = 0;
	while (a_ant[i])
	{
		if (a_ant[i][1] == new->num && new->next != NULL)
			return (0);
		i++;
	}
	return (1);
}

int		ft_short_way(t_room *new, int f, int ***a_ant)
{
	int	c;
	int	val;
	int	rm;

	c = 0;
	rm = -1;
	val = 0;
	while (new)
	{
		if (new->num == (*a_ant)[f][1])
		{
			while (new->qw && new->qw[c])
			{
				if ((new->qw[c]->dist < val) || rm == -1)
				{
					val = new->qw[c]->dist;
					rm = c;
				}
				c++;
			}
		}
		new = new->next;
	}
	return (rm);
}
