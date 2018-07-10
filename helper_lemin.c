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

void	ft_free_double(char **arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == NULL)
			break ;
		ft_strdel(&arr[i++]);
	}
	free(arr);
	arr = NULL;
}

void	ft_helper_newroom(t_room *new, int st_end)
{
	if (st_end == 1 || st_end == 2)
	{
		if (st_end == 1)
			new->str = 1;
		else
			new->end = 1;
	}
	else
	{
		new->str = 0;
		new->end = 0;
	}
}

t_room	*ft_newroom(char **arr, int size, int st_end, int n)
{
	t_room *new;

	new = malloc(sizeof(t_room));
	if (size == 3)
	{
		new->nm_c = ft_strdup(arr[0]);
		new->cr_y = ft_atoi(arr[1]);
		new->cr_x = ft_atoi(arr[2]);
		new->link = NULL;
		new->dist = 2147483647;
		new->mark = 0;
		new->ant = 0;
		new->num = n;
		new->lnk = NULL;
		new->qw = NULL;
		ft_helper_newroom(new, st_end);
		new->next = NULL;
	}
	return (new);
}

void	ft_realloc(char **src, char **line, int cnt, int k)
{
	char	*buff;

	if (!*src)
		*src = ft_strdup(*line);
	else if (*src && line)
	{
		*src = ft_strjoin_myq(*src, "\n");
		cnt = ft_strlen_my(*line);
		buff = ft_strdup(*src);
		ft_strdel(&(*src));
		*src = NULL;
		*src = (char*)malloc(sizeof(char) * (ft_strlen(buff) + cnt + 1));
		cnt = 0;
		while (buff[k])
		{
			(*src)[k] = buff[k];
			k++;
		}
		while ((*line)[cnt])
			(*src)[k++] = (*line)[cnt++];
		(*src)[k] = '\0';
		ft_strdel(&buff);
	}
}

void	ft_free_room(t_room **room)
{
	int		i;
	int		c;
	t_room	*tmp;

	if (!(*room)->next && !(*room)->nm_c)
		return ;
	while (*room)
	{
		i = 0;
		c = 0;
		tmp = (*room)->next;
		if ((*room)->lnk)
		{
			while ((*room)->lnk && (*room)->lnk[i])
				ft_strdel(&(*room)->lnk[i++]);
		}
		free((*room)->lnk);
		ft_strdel(&(*room)->nm_c);
		ft_strdel(&(*room)->link);
		((*room)->qw) ? free((*room)->qw) : 0;
		(*room)->qw = NULL;
		free(*room);
		*room = NULL;
		*room = tmp;
	}
}
