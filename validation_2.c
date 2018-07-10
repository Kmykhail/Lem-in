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

int		ft_check_overlap(t_room *room, t_room *new, char **arr)
{
	int i;
	int c;

	c = 0;
	i = -1;
	i = (!ft_strcmp(room->nm_c, arr[0])) ? 1 : 0;
	while (new)
	{
		if (!ft_strcmp(new->nm_c, arr[i]))
		{
			if (!new->link || !ft_strstr(new->link, room->nm_c))
				return (1);
			else
				return (0);
		}
		new = new->next;
	}
	return (0);
}

int		ft_check_sml(t_lem *lem)
{
	int i;
	int c;

	i = 0;
	c = 0;
	if (!lem->sml)
	{
		lem->sml = (char**)malloc(sizeof(char*) * 2);
		lem->sml[0] = ft_strdup(lem->line);
		lem->sml[1] = NULL;
	}
	else
	{
		if (ft_same_pipe(lem))
		{
			lem->skip = 1;
			return (1);
		}
		ft_helper_check_sml(lem, i, c);
	}
	return (0);
}

int		ft_check_link(char **arr, t_room *room, t_lem *lem)
{
	t_room	*new;

	new = room;
	if (arr[0][0] == 'L' || arr[0][0] == '#' || arr[0][0] == ' ')
		lem->error++;
	if (!lem->error)
	{
		if (ft_check_sml(lem))
			return (lem->skip);
		if (ft_fake_room(lem, arr, 2, 0))
			return (lem->stop++);
		while (room)
		{
			if ((!CMP(room->nm_c, arr[0]) || !CMP(room->nm_c, arr[1])))
				ft_realloc(&room->link, (!CMP(room->nm_c, arr[0]) \
				? &arr[1] : &arr[0]), 0, 0);
			room = room->next;
		}
	}
	return (0);
}

int		ft_anlyze_lne(char *s)
{
	int sp;
	int i;
	int difis;

	sp = 0;
	i = 0;
	difis = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			sp++;
		else if (s[i] == '-')
			difis++;
		i++;
	}
	if ((sp && difis) || (sp > 2 || difis > 1))
		return (1);
	return (0);
}

int		ft_check_case(t_lem *lem, t_room *room, int i)
{
	char	**arr;

	arr = NULL;
	if ((LNE[0] == ' ' || LNE[0] == '\t') || ft_anlyze_lne(LNE))
		return (lem->stop++);
	arr = (CHR(LNE, '-') && !ERROR) ? ft_strsplit(LNE, '-') : arr;
	arr = (CHR(LNE, ' ') && !ERROR) ? ft_strsplit(LNE, ' ') : arr;
	while (arr[i])
		i++;
	if (i == 3)
	{
		if (ft_helper_check_case(room, lem, arr))
			return (ERROR);
	}
	else if (i == 2 && (room->nm_c || room->next))
		ft_check_link(arr, room, lem);
	else
		lem->error++;
	(arr) ? ft_free_double(arr, i) : 0;
	if (lem->error)
	{
		lem->error = 0;
		lem->stop = 1;
	}
	return (0);
}
