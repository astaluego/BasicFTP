/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:23:49 by aderuell          #+#    #+#             */
/*   Updated: 2016/04/25 15:27:09 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static char				*getname(char **command)
{
	char				**tab;
	char				*name;
	int					i;

	if (command[1] && !command[2])
	{
		i = 0;
		tab = ft_strsplit(command[1], '/');
		while (tab[i])
			i++;
		name = ft_strdup(tab[i - 1]);
		freetab(tab);
		return (name);
	}
	return (NULL);
}

static int				getsize(t_client *c)
{
	int					r;
	char				buf[1024];
	int					size;

	r = read(c->sock, buf, 1023);
	if (r > 0)
	{
		buf[r] = '\0';
		size = ft_atoi(buf);
		if (size > 0)
			ft_putendl(ft_itoa(size));
	}
	else
		size = -1;
	return (size);
}

static void				getdata(t_client *c, int size, char *name)
{
	int					fd;
	int					r;
	int					i;
	char				*buf;

	i = 0;
	buf = (char *)malloc(sizeof(char) * size);
	write(c->sock, "ok\n", 3);
	while (i < size)
	{
		r = read(c->sock, buf + i, size - i);
		i += r;
	}
	fd = open(name, O_CREAT | O_RDWR, 0777);
	write(fd, buf, size);
	close(fd);
	free(buf);
	buf = NULL;
	ft_putendl("SUCCES");
}

void					get(t_client *c, char *line, char **command)
{
	char				*name;
	int					size;
	int					r;
	char				buf[1024];

	write(c->sock, line, ft_strlen(line) + 1);
	name = getname(command);
	if (name != NULL)
	{
		ft_putstr("Trying to receive : ");
		ft_putendl(name);
		size = getsize(c);
		if (size <= 0)
		{
			ft_putendl("ERROR --> File cannot be accessed");
			return ;
		}
		getdata(c, size, name);
		return ;
	}
	r = read(c->sock, buf, 1023);
	buf[r] = '\0';
	ft_putstr(buf);
}
