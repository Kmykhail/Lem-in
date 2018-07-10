/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmykhail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 11:03:17 by kmykhail          #+#    #+#             */
/*   Updated: 2017/12/08 11:03:22 by kmykhail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define JOIN ft_strjoin_my(save->content, buff)

char	*ft_line(char *mass)
{
	size_t	start;
	char	*result;

	if (!ft_strchr(mass, '\n'))
		result = ft_strdup(mass);
	else
	{
		start = ft_strlen(mass) - ft_strlen(ft_strchr(mass, '\n'));
		result = ft_strsub(mass, 0, start);
	}
	return (result);
}

char	*ft_del_mem(char *mass)
{
	size_t	l;
	char	*arr;

	l = 0;
	if (ft_strchr(mass, '\n'))
	{
		while (mass[l] != '\n' && mass[l])
			l++;
		if (!mass[l + 1])
		{
			free(mass);
			return (NULL);
		}
		arr = ft_strdup(&mass[l + 1]);
		free(mass);
		mass = ft_strdup(arr);
		free(arr);
	}
	return (mass);
}

char	*ft_strjoin_my(char *s1, char *s2)
{
	int		i;
	int		l;
	char	*qw;

	i = 0;
	l = 0;
	if ((char*)s1 == NULL || (char*)s2 == NULL)
		return (NULL);
	qw = (char*)malloc(sizeof(qw) * (ft_strlen((char*)s1)\
	+ ft_strlen((char*)s2)));
	if (!qw)
		return (NULL);
	while (((char*)s1)[i])
	{
		qw[i] = s1[i];
		i++;
	}
	while (((char*)s2)[l])
		qw[i++] = s2[l++];
	ft_strdel(&s1);
	qw[i] = '\0';
	return (qw);
}

t_list	*ft_list_part(t_list **new, int fd)
{
	t_list	*two;

	if (*new == NULL)
	{
		*new = ft_lstnew(NULL, 0);
		(*new)->cnt = fd;
		return (*new);
	}
	if ((*new)->cnt != fd)
	{
		two = *new;
		while (two->next)
		{
			if (two->cnt == fd)
				return (two);
			two = two->next;
		}
		if (two->cnt == fd)
			return (two);
		two->next = ft_lstnew(NULL, 0);
		two->next->cnt = fd;
		return (two->next);
	}
	return (*new);
}

int		get_next_line(int fd, char **line)
{
	static	t_list	*new = NULL;
	char			buff[BUFF_SIZE + 1];
	t_list			*save;

	if (line == NULL || fd < 0)
		return (-1);
	save = ft_list_part(&new, fd);
	while ((save->i = read(fd, buff, BUFF_SIZE)))
	{
		if (save->i == -1)
			return (-1);
		buff[save->i] = '\0';
		save->content = (!save->content) ? ft_strdup(buff) : JOIN;
		*line = ft_line(save->content);
		if (ft_strchr(save->content, '\n'))
			return ((save->content = ft_del_mem(save->content)) ? 1 : 1);
		free(*line);
	}
	if (save->content)
		*line = ft_line(save->content);
	else
		return (0);
	if (ft_strchr(save->content, '\n'))
		return ((save->content = ft_del_mem(save->content)) ? 1 : 1);
	return ((save->content = NULL) ? 1 : 1);
}
