/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:27:56 by aderuell          #+#    #+#             */
/*   Updated: 2016/04/25 15:28:37 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

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
	int						sock;
	int						r;
	pid_t					pid;
	unsigned int			sin_len;
	char					buff[BUFF_SIZE];
	struct sockaddr_in		sin;
}							t_client;

typedef struct				s_server
{
	int						port;
	int						sock;
	int						count;
	char					*homedir;
}							t_server;

int							error(char *str);
void						usage(char *str);
void						normalize(char *str);
void						freetab(char **tab);
char						*getname(t_client *c, char **command);
void						get(t_client *c, char **command);
void						put(t_client *c, char **comnand);
void						rm(t_client*c, char **command);
void						quit(t_client *c, char **command);
void						pwd(t_client *c, char **command);
void						ls(t_client *c, char **command);
void						cd(t_client *c, t_server *s, char **command);
t_server					*init_server(char *str);

#endif
