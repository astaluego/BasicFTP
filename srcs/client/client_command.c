/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:23:39 by aderuell          #+#    #+#             */
/*   Updated: 2016/04/25 15:23:40 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void					lcd(t_client *c, char **command)
{
	if (!command[1])
	{
		chdir(c->homedir);
		ft_putendl("SUCCES");
	}
	else if (command[2])
		ft_putendl("ERROR --> Too many arguments for lcd");
	else
	{
		if (chdir(command[1]) == -1)
			ft_putendl("ERROR --> Directory cannot be accessed");
		else
			ft_putendl("SUCCES");
	}
}

void					lpwd(char **command)
{
	if (command[1])
		ft_putendl("ERROR --> Too many arguments for lpwd");
	else
	{
		ft_putendl(getcwd(NULL, 0));
		ft_putendl("SUCCES");
	}
}

void					lls(char **command)
{
	int					id;

	id = fork();
	if (id == 0)
		execv("/bin/ls", command);
	else
		wait4(id, 0, 0, 0);
	ft_putendl("SUCCES");
}

void					lrm(char **command)
{
	if (!command[1])
		ft_putendl("ERROR --> Not enough arguments for lrm");
	else if (command[2])
		ft_putendl("ERROR --> Too many arguments for lrm");
	else
	{
		if (unlink(command[1]) == -1)
			ft_putendl("ERROR --> File cannot be accessed");
		else
			ft_putendl("SUCCES");
	}
}
