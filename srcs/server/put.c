/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:17:10 by aderuell          #+#    #+#             */
/*   Updated: 2016/04/25 15:17:11 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char					*getname(t_client *c, char **command)
{
	char				**tab;
	char				*name;
	int					i;

	if (!command[1])
	{
		write(c->sock, "ERROR --> Not enough arguments\n", 31);
		return (NULL);
	}
	if (command[2])
	{
		write(c->sock, "ERROR --> Too many arguments\n", 29);
		return (NULL);
	}
	tab = ft_strsplit(command[1], '/');
	i = 0;
	while (tab[i])
		i = i + 1;
	name = ft_strdup(tab[i - 1]);
	freetab(tab);
	return (name);
}

static int				getsize(t_client *c)
{
	int					r;
	int					size;
	char				buff[1024];

	r = read(c->sock, buff, 1023);
	if (r > 0)
	{
		buff[r] = '\0';
		size = ft_atoi(buff);
		ft_putchar('\t');
		ft_putnbr(size);
		ft_putchar('\n');
	}
	else
		size = -1;
	return (size);
}

static void				getdata(t_client *c, int size, int fd)
{
	int					r;
	char				*buff;
	int					i;

	i = 0;
	buff = (char *)malloc(sizeof(char) * size);
	while (i < size)
	{
		r = read(c->sock, buff + i, size - i);
		i += r;
	}
	write(fd, buff, size);
	free(buff);
}

void					put(t_client *c, char **command)
{
	int					size;
	int					fd;
	char				*name;

	name = getname(c, command);
	if (name != NULL)
	{
		ft_putstr("\n\tTrying to receive -> ");
		ft_putendl(name);
		write(c->sock, "ok", 3);
		if ((size = getsize(c)) <= 0)
		{
			write(c->sock, "ERROR --> File cannot be accessed\n", 34);
			ft_putendl("\tError\n");
			return ;
		}
		fd = open(name, O_CREAT | O_RDWR, 0777);
		getdata(c, size, fd);
		close(fd);
		write(c->sock, "SUCCES\n", 7);
		ft_putendl("\tFile received\n");
	}
}
