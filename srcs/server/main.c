/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:17:05 by aderuell          #+#    #+#             */
/*   Updated: 2016/04/25 15:19:19 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void					process(t_client *c, t_server *s, char **command)
{
	if (ft_strcmp("quit", command[0]) == 0)
		quit(c, command);
	else if (ft_strcmp("ls", command[0]) == 0)
		ls(c, command);
	else if (ft_strcmp("cd", command[0]) == 0)
		cd(c, s, command);
	else if (ft_strcmp("pwd", command[0]) == 0)
		pwd(c, command);
	else if (ft_strcmp("put", command[0]) == 0)
		put(c, command);
	else if (ft_strcmp("get", command[0]) == 0)
		get(c, command);
	else if (ft_strcmp("rm", command[0]) == 0)
		rm(c, command);
	else
		write(c->sock, "ERROR --> Unknown command\n", 22);
}

void					read_command(t_client *c, t_server *s)
{
	char				**command;

	if (c == NULL)
		error("We lost the client");
	c->buff[c->r - 1] = '\0';
	normalize(c->buff);
	command = ft_strsplit(c->buff, ' ');
	if (command[0])
	{
		ft_putstr("\nReceived ");
		ft_putnbr(c->r);
		ft_putstr(" bytes.\nMessage: ");
		ft_putendl(c->buff);
		process(c, s, command);
	}
	freetab(command);
}

int						main(int ac, char **av)
{
	t_server			*s;
	t_client			c;

	if (ac != 2)
		usage(av[0]);
	s = init_server(av[1]);
	while ((c.sock = accept(s->sock,
		(struct sockaddr *)&(c.sin), &c.sin_len)) > 0)
	{
		if ((c.pid = fork()) == -1)
			close(c.sock);
		else if (c.pid > 0)
		{
			close(c.sock);
			s->count = s->count + 1;
			continue ;
		}
		else if (c.pid == 0)
			s->count = s->count + 1;
		while ((c.r = read(c.sock, c.buff, BUFF_SIZE - 1)) > 0)
			read_command(&c, s);
	}
	close(s->sock);
	free(s);
	return (0);
}
