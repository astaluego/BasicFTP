/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:24:08 by aderuell          #+#    #+#             */
/*   Updated: 2016/04/25 15:26:47 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int				getsize(char **command)
{
	struct stat			s;
	int					fd;

	if (!command[1])
		return (-1);
	if ((fd = open(command[1], O_RDONLY)) == -1)
		return (-1);
	fstat(fd, &s);
	if (!(S_ISREG(s.st_mode)))
		return (-1);
	return (s.st_size);
}

static void				send_data(t_client *c, char **command)
{
	struct stat			s;
	int					size;
	int					fd;
	char				*f;

	fd = open(command[1], O_RDONLY);
	fstat(fd, &s);
	size = s.st_size;
	f = (char *)mmap(0, size, PROT_READ, MAP_PRIVATE, fd, 0);
	write(c->sock, f, size);
	close(fd);
}

void					put(t_client *c, char *line, char **command)
{
	int					r;
	int					size;
	char				buf[1024];
	char				*tmp;

	write(c->sock, line, ft_strlen(line) + 1);
	r = read(c->sock, buf, 3);
	if (r != -1 && ft_strcmp(buf, "ok") == 0)
	{
		size = getsize(command);
		write(c->sock, ft_itoa(size), ft_strlen(ft_itoa(size)));
		send_data(c, command);
		r = read(c->sock, buf, 1023);
		buf[r] = '\0';
		ft_putstr(buf);
		return ;
	}
	r = read(c->sock, buf, 1023);
	buf[r] = '\0';
	tmp = ft_strjoin("ERR", buf);
	ft_putstr(tmp);
}
