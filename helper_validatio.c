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

int		ft_fake_room(t_lem *lem, char **find, int nm, int i)
{
	int c;

	c = 0;
	if (nm == 3)
	{
		while (lem->rooms[i])
		{
			if (STRSTR(ROOMS[i], find[0]) || \
			(COORS[c] == ft_atoi(find[1]) && COORS[c + 1] == ft_atoi(find[2])))
				return (1);
			i++;
			c += 2;
		}
	}
	else if (nm == 2)
	{
		while (lem->rooms[i])
		{
			c += (STRSTR(ROOMS[i], find[0]) \
			|| STRSTR(ROOMS[i], find[1])) ? 1 : 0;
			i++;
		}
		return ((c == 1 || c == 0) ? 1 : 0);
	}
	return (0);
}

void	ft_help_check_rm(t_lem *lem, char **arr, int cnt, int i)
{
	char **buff;

	ft_realloc_coor(lem, arr, 0, 0);
	while (lem->rooms[cnt])
		cnt++;
	buff = (char**)malloc(sizeof(char*) * (cnt + 1));
	while (i < cnt)
	{
		buff[i] = ft_strdup(lem->rooms[i]);
		i++;
	}
	buff[i] = NULL;
	ft_free_double(lem->rooms, cnt);
	lem->rooms = (char**)malloc(sizeof(char*) * (cnt + 2));
	i = 0;
	while (i < cnt)
	{
		lem->rooms[i] = ft_strdup(buff[i]);
		i++;
	}
	lem->rooms[i++] = ft_strdup(arr[0]);
	lem->rooms[i] = NULL;
	ft_free_double(buff, cnt);
}

int		ft_same_pipe(t_lem *lem)
{
	int i;

	i = 0;
	while (lem->sml[i])
	{
		if (!CMP(lem->sml[i], lem->line))
			return (1);
		i++;
	}
	return (0);
}

int		ft_helper_check_case(t_room *room, t_lem *lem, char **arr)
{
	if ((arr[0][0] == 'L' || arr[0][0] == '#' || arr[0][0] == ' ') && \
	ft_dig_all(arr[1]) && ft_dig_all(arr[2]))
		lem->error++;
	else if ((arr[0][0] != 'L' && arr[0][0] != '#' && arr[0][0] != ' ') && \
	(!ft_dig_all(arr[1]) || !ft_dig_all(arr[2])))
		lem->error++;
	else if ((arr[0][0] != 'L' && arr[0][0] != '#' && arr[0][0] != ' ') &&\
	ft_dig_all(arr[1]) && ft_dig_all(arr[2]) && (lem->str || lem->end))
	{
		if (ft_check_room(arr, lem) && !ERROR)
			return (ERROR++);
		while (room->next)
			room = room->next;
		room->next = ft_newroom(arr, 3, 0, lem->indx++);
	}
	else
		lem->error = 0;
	return (0);
}

void	ft_helper_check_sml(t_lem *lem, int i, int c)
{
	char	**tmp;

	while (lem->sml[i])
		i++;
	tmp = (char**)malloc(sizeof(char*) * (i + 1));
	while (c < i)
	{
		tmp[c] = ft_strdup(lem->sml[c]);
		c++;
	}
	tmp[c] = NULL;
	ft_free_double(lem->sml, i);
	lem->sml = (char**)malloc(sizeof(char*) * (i + 2));
	c = 0;
	while (c < i)
	{
		lem->sml[c] = ft_strdup(tmp[c]);
		c++;
	}
	lem->sml[c++] = ft_strdup(lem->line);
	lem->sml[c] = NULL;
	ft_free_double(tmp, i);
}
