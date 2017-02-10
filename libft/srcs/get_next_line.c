/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/08 17:15:17 by aderuell          #+#    #+#             */
/*   Updated: 2015/02/03 18:39:59 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static void				copy_line(char **line, t_file *file)
{
	size_t				len;
	char				*tmp;

	len = ft_strchr(file->buff, '\n') - file->buff;
	*line = ft_strsub(file->buff, 0, len);
	tmp = file->buff;
	file->buff = ft_strdup(ft_strchr(file->buff, '\n') + 1);
	free(tmp);
}

static void				copy_buff_into_tmp(char *buff, t_file *file, int ret)
{
	char				*tmp;

	buff[ret] = '\0';
	tmp = file->buff;
	file->buff = ft_strjoin(tmp, buff);
	free(tmp);
}

static int				parse_line(t_file *file, char **line)
{
	char				buff[BUFF_SIZE + 1];
	int					ret;

	if (line == NULL || file->fd < 0 || BUFF_SIZE < 1 || BUFF_SIZE > SSIZE_MAX)
		return (-1);
	if (!file->buff)
	{
		file->buff = ft_strnew(0);
		if (file->buff == NULL)
			return (-1);
	}
	while (ft_strchr(file->buff, '\n') == 0
			&& (ret = read(file->fd, buff, BUFF_SIZE)) > 0)
		copy_buff_into_tmp(buff, file, ret);
	if (ret < 0)
		return (-1);
	if (ret == 0 && ft_strchr(file->buff, '\n') == 0)
	{
		*line = file->buff;
		file->buff = NULL;
		return (0);
	}
	copy_line(line, file);
	return (1);
}

int						get_next_line(int const fd, char **line)
{
	static t_file		*multi_fd;
	t_file				*new;

	if (!multi_fd)
	{
		multi_fd = (t_file *)malloc(sizeof(t_file));
		multi_fd->fd = fd;
		multi_fd->buff = NULL;
		multi_fd->next = NULL;
		multi_fd->start = multi_fd;
		return (parse_line(multi_fd, line));
	}
	multi_fd = multi_fd->start;
	while (multi_fd->next != NULL && multi_fd->fd != fd)
		multi_fd = multi_fd->next;
	if (multi_fd->fd == fd)
		return (parse_line(multi_fd, line));
	new = (t_file *)malloc(sizeof(t_file));
	new->fd = fd;
	new->buff = NULL;
	new->next = NULL;
	new->start = multi_fd->start;
	multi_fd->next = new;
	return (parse_line(new, line));
}
