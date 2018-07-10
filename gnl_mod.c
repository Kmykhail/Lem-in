/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:16:18 by kmykhail          #+#    #+#             */
/*   Updated: 2018/02/22 15:16:20 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_lst	*search_and_append(t_lst **head, int fd)
{
	t_lst	*q_tmp;
	t_lst	*new;

	q_tmp = *head;
	if (q_tmp && q_tmp->fd == fd)
		return (q_tmp);
	while (q_tmp && q_tmp->next != NULL)
	{
		q_tmp = q_tmp->next;
		if (q_tmp->fd == fd)
			return (q_tmp);
	}
	new = (t_lst*)malloc(sizeof(t_lst));
	if (new == NULL)
		return (NULL);
	new->fd = fd;
	new->str = NULL;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	q_tmp->next = new;
	return (new);
}

int		check_str(char **line, char **str)
{
	int		st;
	int		i;
	char	*q_tmp;

	i = 0;
	st = i;
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] == '\n')
		{
			q_tmp = *str;
			*line = ft_strsub(*str, st, i - st);
			*str = ft_strsub(*str, i - st + 1, ft_strlen(*str) - (i - st));
			free(q_tmp);
			q_tmp = NULL;
			return (1);
		}
		i++;
	}
	return (0);
}

int		readfile(int fd, t_lst *q_tmp, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		cnt;
	char	*dd;

	while ((cnt = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[cnt] = '\0';
		if (q_tmp->str)
		{
			dd = q_tmp->str;
			if (!(q_tmp->str = ft_strjoin(q_tmp->str, buf)))
				return (-1);
			free(dd);
		}
		if (!(q_tmp->str))
			if (!(q_tmp->str = ft_strdup(buf)))
				return (-1);
		if (check_str(line, &(q_tmp->str)) == 1)
			return (1);
	}
	if (cnt == -1)
		return (-1);
	return (0);
}

int		get_next_line_q(const int fd, char **line)
{
	static t_lst	*head = NULL;
	t_lst			*q_tmp;

	if (line == NULL)
		return (-1);
	q_tmp = search_and_append(&head, fd);
	if ((q_tmp->str && check_str(line, &(q_tmp->str)) == 1) ||
		(readfile(fd, q_tmp, line) == 1))
		return (1);
	if (readfile(fd, q_tmp, line) == -1)
		return (-1);
	if ((q_tmp->str) && ((q_tmp->str)[0] != '\0'))
	{
		*line = ft_strsub(q_tmp->str, 0, ft_strlen(q_tmp->str));
		free(q_tmp->str);
		q_tmp->str = NULL;
		return (1);
	}
	return (0);
}
