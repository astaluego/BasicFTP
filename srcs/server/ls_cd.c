/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:16:57 by aderuell          #+#    #+#             */
/*   Updated: 2016/04/25 15:41:21 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int				check_ls(char *str)
{
	int					i;

	i = 1;
	if (str == NULL)
		return (1);
	if (str[0] != '-')
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] != 'a' && str[i] != 'l')
			return (-1);
		i = i + 1;
	}
	return (1);
}

void					ls(t_client *c, char **command)
{
	pid_t				id;

	if (command[1] && check_ls(command[1]) == -1)
	{
		write(c->sock, "ERROR --> Could only execute ls -la -a -l\n", 57);
		return ;
	}
	id = fork();
	if (id == 0)
	{
		dup2(c->sock, 1);
		execv("/bin/ls", command);
	}
	else
		wait4(id, 0, 0, 0);
	write(c->sock, "SUCCES\n", 7);
}

static int				check_cd(t_client *c, t_server *s, char **command)
{
	if (!command[1])
	{
		chdir(s->homedir);
		write(c->sock, "SUCCES\n", 7);
		return (-1);
	}
	else if (command[2])
	{
		write(c->sock, "ERROR --> Too many arguments for cd\n", 36);
		return (-1);
	}
	return (1);
}

void					cd(t_client *c, t_server *s, char **command)
{
	char				*current_path;

	if (check_cd(c, s, command) == -1)
		return ;
	current_path = getcwd(NULL, 0);
	if ((chdir(command[1])) == -1)
		write(c->sock, "ERROR --> Invalid directory\n", 28);
	else
	{
		if (ft_strlen(getcwd(NULL, 0)) < ft_strlen(s->homedir))
		{
			chdir(current_path);
			write(c->sock,
					"ERROR --> Dir is beyond serveur's root directory\n", 55);
		}
		else
			write(c->sock, "SUCCES\n", 7);
	}
	free(current_path);
}

void					rm(t_client *c, char **command)
{
	if (!command[1])
		write(c->sock, "ERROR --> Not enough arguments for rm\n", 38);
	else if (command[2])
		write(c->sock, "ERROR --> Too much arguments for rm\n", 36);
	else
	{
		if (unlink(command[1]) == -1)
			write(c->sock, "ERROR --> File cannot be accessed\n", 36);
		else
			write(c->sock, "SUCCES\n", 7);
	}
}
