/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:27:51 by aderuell          #+#    #+#             */
/*   Updated: 2016/04/25 15:29:00 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/socket.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <fcntl.h>

typedef struct				s_client
{
	int						port;
	int						sock;
	char					*homedir;
	struct sockaddr_in		sin;
}							t_client;

int							error(char *str);
void						usage(char *str);
void						normalize(char *str);
void						freetab(char **tab);
void						lcd(t_client *c, char **command);
void						lpwd(char **command);
void						lls(char **command);
void						lrm(char **command);
void						get(t_client *c, char *line, char **command);
void						put(t_client *c, char *line, char **command);
void						quit(t_client *c, char *line);
void						ls(t_client *c, char *line);
void						defaut(t_client *c, char *line);
t_client					*init_client(char *e, char *h, char *p);

#endif
