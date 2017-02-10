/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:16:49 by aderuell          #+#    #+#             */
/*   Updated: 2016/04/25 15:17:56 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static int				get_port(char *str)
{
	int					i;

	i = 0;
	if (ft_strlen(str) != 4)
		error("Wrong port");
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			error("Wrong port");
		i = i + 1;
	}
	return (ft_atoi(str));
}

static int				create_server(int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	proto = getprotobyname("tcp");
	if (!proto)
		error("Could not find TCP protocol");
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (struct sockaddr *)&sin, sizeof(sin)) == -1)
		error("Bind failed");
	listen(sock, 100);
	return (sock);
}

static char				*get_homedir(void)
{
	char				buff[1024];
	char				*homedir;

	if (getcwd(buff, sizeof(buff)) == NULL)
		error("Could not get homedir");
	homedir = ft_strdup(buff);
	ft_putstr("HOME: ");
	ft_putendl(homedir);
	return (homedir);
}

t_server				*init_server(char *str)
{
	t_server			*s;

	s = (t_server *)malloc(sizeof(t_server));
	if (s == NULL)
		error("Malloc failed");
	s->count = 0;
	s->port = get_port(str);
	s->sock = create_server(s->port);
	ft_putstr("PORT: ");
	ft_putendl(str);
	s->homedir = get_homedir();
	return (s);
}
