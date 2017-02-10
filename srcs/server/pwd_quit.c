/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_quit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:17:16 by aderuell          #+#    #+#             */
/*   Updated: 2016/04/25 15:17:17 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void					quit(t_client *c, char **command)
{
	if (command[1])
	{
		write(c->sock, "ERROR --> Quit does'nt need any argument\n", 41);
		return ;
	}
	write(c->sock, "SUCCES\n", 7);
	close(c->sock);
}

void					pwd(t_client *c, char **command)
{
	char				*path;

	if (!command[1])
	{
		path = ft_strcat(getcwd(NULL, 0), "\nSUCCES\n");
		write(c->sock, path, ft_strlen(path));
	}
	else
		write(c->sock, "ERROR --> Too many arguments for pwd\n", 37);
}
