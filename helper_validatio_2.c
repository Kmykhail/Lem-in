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

int		ft_check_ants(char *line, t_lem *lem)
{
	int i;
	int ok;

	i = 0;
	ok = 0;
	while (line[i] && !lem->error)
	{
		if (ft_isdigit(line[i]))
			ok++;
		ok = (line[i] == '0' && !i) ? 0 : ok;
		i++;
	}
	lem->error += (ok < ft_strlen_my(line) && !lem->error) ? 1 : 0;
	if (!lem->error)
	{
		lem->s_ant = ft_atoi(line);
		lem->s_ant = (lem->s_ant == MAX_ANT) ? MA_ANT : lem->s_ant;
		if (lem->s_ant < 0)
			ERROR++;
	}
	return ((lem->error) ? 1 : 0);
}

void	ft_realloc_coor(t_lem *lem, char **arr, int i, int c)
{
	int *tmp_yx;

	while (lem->coors[i] != -100)
		i += 2;
	tmp_yx = malloc(sizeof(int) * (i + 2));
	while (c < i)
	{
		tmp_yx[c] = lem->coors[c];
		c++;
	}
	tmp_yx[c++] = -100;
	tmp_yx[c] = -100;
	free(lem->coors);
	lem->coors = malloc(sizeof(int) * (c + 4));
	c = 0;
	while (c < i)
	{
		lem->coors[c] = tmp_yx[c];
		c++;
	}
	lem->coors[c++] = ft_atoi(arr[1]);
	lem->coors[c++] = ft_atoi(arr[2]);
	lem->coors[c] = -100;
	free(tmp_yx);
}

int		ft_check_room(char **arr, t_lem *lem)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	if (!lem->rooms)
	{
		lem->rooms = (char**)malloc(sizeof(char*) * 3);
		lem->rooms[0] = ft_strdup(arr[0]);
		lem->rooms[1] = NULL;
		lem->coors = malloc(sizeof(int) * 4);
		lem->coors[0] = ft_atoi(arr[1]);
		lem->coors[1] = ft_atoi(arr[2]);
		lem->coors[2] = -100;
		lem->coors[3] = -100;
	}
	else if (lem->rooms)
	{
		if (ft_fake_room(lem, arr, 3, 0))
			return (1);
		ft_help_check_rm(lem, arr, cnt, i);
	}
	return (0);
}

void	ft_init_room(t_room *room, t_lem *lem, char **arr)
{
	room->nm_c = ft_strdup(arr[0]);
	room->cr_y = ft_atoi(arr[1]);
	room->cr_x = ft_atoi(arr[2]);
	room->link = NULL;
	room->dist = 2147483647;
	room->mark = 0;
	room->ant = 0;
	room->num = lem->indx++;
	room->lnk = NULL;
	room->qw = NULL;
	if (ST_END == 1)
		room->str = 1;
	else
		room->end = 1;
}
