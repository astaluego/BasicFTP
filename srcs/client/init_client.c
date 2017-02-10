/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:23:56 by aderuell          #+#    #+#             */
/*   Updated: 2016/04/25 15:25:21 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int						get_port(char *str)
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

int						create_client(char *hostname, int port)
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
	sin.sin_addr.s_addr = inet_addr(hostname);
	if (connect(sock, (const struct sockaddr *)&sin,
			sizeof(sin)) == -1)
		error("Connect error");
	return (sock);
}

char					*get_hostname(char *hostname)
{
	struct hostent	*h;

	if (!(h = gethostbyname(hostname)))
		return (NULL);
	return (inet_ntoa(*((struct in_addr *)h->h_addr)));
}

char					*get_homedir(void)
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

t_client				*init_client(char *exec, char *hostname, char *port)
{
	t_client			*client;

	(void)hostname;
	client = (t_client *)malloc(sizeof(t_client));
	if (client == NULL)
		error("Malloc failed");
	client->port = get_port(port);
	if ((hostname = get_hostname(hostname)) == NULL)
		usage(exec);
	client->sock = create_client(hostname, client->port);
	client->homedir = get_homedir();
	return (client);
}
