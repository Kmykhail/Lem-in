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

void	ft_start_end_room(t_lem *lem, t_room *room, char **arr)
{
	if (ST_END == 1)
		STR = 1;
	else
		END = 1;
	if (room->nm_c)
	{
		while (room->next)
			room = room->next;
		if (ST_END == 1)
			room->next = ft_newroom(arr, 3, 1, lem->indx++);
		else if (ST_END == 2)
			room->next = ft_newroom(arr, 3, 2, lem->indx++);
	}
	else
		ft_init_room(room, lem, arr);
}

int		ft_start_end_rm(t_lem *lem, t_room *room)
{
	char	**arr;
	int		l;

	l = 0;
	arr = NULL;
	if (lem->st_end_r == 1 || lem->st_end_r == 2)
	{
		if ((LNE[0] == ' ' || LNE[0] == '\t') || ft_anlyze_lne(LNE))
			return (ERROR++);
		arr = ft_strsplit(LNE, ' ');
		while (arr[l])
			l++;
		ERROR += (l != 3) ? 1 : 0;
		ERROR += (!ERROR && (ARR == 'L' || ARR == '#' || ARR == ' ')) ? 1 : 0;
		ERROR += (!ERROR && (!ft_dig_all(arr[1]))) ? 1 : 0;
		ERROR += (!ERROR && !ft_dig_all(arr[2])) ? 1 : 0;
		ERROR += (!ERROR && ft_check_room(arr, lem)) ? 1 : 0;
	}
	if ((ST_END == 1 || ST_END == 2) && !ERROR)
		ft_start_end_room(lem, room, arr);
	ST_END = 0;
	(arr) ? ft_free_double(arr, 3) : 0;
	return (ERROR);
}

int		ft_helper_check_line(t_lem *lem, t_room *room, int i)
{
	if (lem->itr && LNE[i] == '#' && !ERROR)
	{
		if ((ST_END == 1 && !lem->str && !lem->end) \
		|| (ST_END == 2 && lem->str && !lem->end))
		{
			if (!CMP(LNE, "##end") || !CMP(LNE, "##start"))
				ERROR++;
		}
		else if (!CMP(&LNE[i + 2], "start") && !lem->str)
			lem->st_end_r = 1;
		else if (!CMP(&LNE[i + 2], "end") && !lem->end)
			lem->st_end_r = 2;
		else if (LNE[i + 1] != '#' || (LNE[i + 1] == '#' && \
		CMP(&LNE[i + 2], "start") && CMP(&LNE[i + 2], "end")))
			return (0);
		else
			lem->stop++;
	}
	else if (lem->itr && (ST_END == 1 || ST_END == 2) && !ERROR)
		ft_start_end_rm(lem, room);
	else if (ITR && !ERROR && (CHR(LNE, '-') || CHR(LNE, ' ')) && room->nm_c)
		ft_check_case(lem, room, 0);
	else
		(room->nm_c && ROOMS && !ERROR) ? (lem->stop = 1) : (ERROR += 1);
	return (0);
}

int		ft_check_line(t_lem *lem, t_room *room)
{
	int i;

	i = 0;
	lem->skip = 0;
	if (!lem->line)
		return (1);
	if (!lem->itr && LNE[i] == '#' && LNE[i + 1] == '#' && \
	CMP(&LNE[i + 2], "start") && CMP(&LNE[i + 2], "end"))
		return (2);
	else if (!lem->itr && LNE[i] == '#' && LNE[i + 1] != '#')
		return (2);
	if (!lem->itr && !ERROR)
		ft_check_ants(LNE, lem);
	else
	{
		if (ft_helper_check_line(lem, room, i) == 2)
			return (2);
	}
	return ((lem->error || lem->stop) ? 1 : 0);
}

int		ft_valid(t_lem *lem, t_room *room)
{
	int k;
	int	fd;

	k = 0;
	fd = 0;
	while (1 && !lem->error && !lem->stop)
	{
		get_next_line_q(fd, &lem->line);
		if ((k = ft_check_line(lem, room)) == 1)
		{
			ft_strdel(&lem->line);
			break ;
		}
		(!lem->skip) ? ft_realloc(&lem->stor, &lem->line, 0, 0) : 0;
		ft_strdel(&lem->line);
		lem->itr += (k == 2 || lem->skip) ? 0 : 1;
		lem->ires++;
	}
	if (!lem->ires && !ERROR)
		return (-1);
	if (ERROR || (STR && !END))
		if (ft_analyze_data(room, lem, 0))
			return (0);
	ft_parse_algo(lem, room, 0);
	return (0);
}
