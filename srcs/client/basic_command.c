/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:23:32 by aderuell          #+#    #+#             */
/*   Updated: 2016/04/25 15:23:34 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void					quit(t_client *c, char *line)
{
	int					r;
	char				buf[1024];

	write(c->sock, line, ft_strlen(line) + 1);
	r = read(c->sock, buf, 1023);
	buf[r] = '\0';
	ft_putstr(buf);
	if (ft_strcmp(buf, "SUCCES\n") == 0)
	{
		close(c->sock);
		exit(0);
	}
}

void					ls(t_client *c, char *line)
{
	int					r;
	int					i;
	char				buf[1024];

	i = 0;
	write(c->sock, line, ft_strlen(line) + 1);
	while (1)
	{
		r = read(c->sock, buf, 1023);
		buf[r] = '\0';
		ft_putstr(buf);
		if (ft_strstr(buf, "ERROR"))
			i = 1;
		if (r < 1023)
			break ;
	}
	if (i == 0)
	{
		r = read(c->sock, buf, 1023);
		buf[r] = '\0';
		ft_putstr(buf);
	}
}

void					defaut(t_client *c, char *line)
{
	int					r;
	char				buf[1024];

	write(c->sock, line, ft_strlen(line) + 1);
	r = read(c->sock, buf, 1023);
	buf[r] = '\0';
	ft_putstr(buf);
}
