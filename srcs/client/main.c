/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:24:03 by aderuell          #+#    #+#             */
/*   Updated: 2016/04/25 15:27:32 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void					process(t_client *c, char **command, char *line)
{
	if (ft_strcmp("quit", command[0]) == 0)
		quit(c, line);
	else if (ft_strcmp("ls", command[0]) == 0)
		ls(c, line);
	else if (ft_strcmp("cd", command[0]) == 0)
		defaut(c, line);
	else if (ft_strcmp("pwd", command[0]) == 0)
		defaut(c, line);
	else if (ft_strcmp("put", command[0]) == 0)
		put(c, line, command);
	else if (ft_strcmp("get", command[0]) == 0)
		get(c, line, command);
	else if (ft_strcmp("rm", command[0]) == 0)
		defaut(c, line);
	else if (ft_strcmp("lcd", command[0]) == 0)
		lcd(c, command);
	else if (ft_strcmp("lpwd", command[0]) == 0)
		lpwd(command);
	else if (ft_strcmp("lls", command[0]) == 0)
		lls(command);
	else if (ft_strcmp("lrm", command[0]) == 0)
		lrm(command);
	else
		ft_putendl("ERROR --> Unknown command");
}

void					read_command(t_client *client, char *line)
{
	char				**command;

	if (client == NULL)
		error("We lost the client");
	normalize(line);
	command = ft_strsplit(line, ' ');
	if (command[0])
		process(client, command, line);
	freetab(command);
}

int						main(int ac, char **av)
{
	t_client			*client;
	char				*line;

	if (ac != 3)
		usage(av[0]);
	client = init_client(av[0], av[1], av[2]);
	while (1)
	{
		ft_putstr("Client $>  ");
		get_next_line(0, &line);
		read_command(client, line);
		free(line);
		line = NULL;
	}
	close(client->sock);
	free(client);
	return (0);
}
