/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:16:43 by aderuell          #+#    #+#             */
/*   Updated: 2016/04/25 15:16:45 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static char				*computesize(char *name_path)
{
	struct stat			s;
	int					fd;
	char				*size;

	if ((fd = open(name_path, O_RDONLY)) == -1)
		return (NULL);
	fstat(fd, &s);
	if (!(S_ISREG(s.st_mode)))
		return (NULL);
	size = ft_itoa(s.st_size);
	return (size);
}

static void				senddata(t_client *c, char **command)
{
	struct stat			s;
	int					fd;
	char				*file;
	int					r;
	char				buf[14];

	r = read(c->sock, buf, 13);
	if (ft_strcmp("ok\n", buf) == 0)
	{
		ft_putendl("\t...sending");
		fd = open(command[1], O_RDONLY);
		fstat(fd, &s);
		file = (char *)mmap(0, s.st_size + 1, PROT_READ,
						MAP_FILE | MAP_PRIVATE, fd, 0);
		write(c->sock, file, s.st_size);
		close(fd);
		ft_putendl("\tFile send\n");
	}
	else
		ft_putendl("\tFailed\n");
}

void					get(t_client *c, char **command)
{
	char				*name;
	char				*size;

	name = getname(c, command);
	if (name != NULL)
	{
		ft_putstr("\n\tTrying to send -> ");
		ft_putendl(name);
		if ((size = computesize(command[1])) == NULL)
		{
			write(c->sock, "-1\n", 3);
			ft_putendl("\tError\n");
			return ;
		}
		ft_putchar('\t');
		ft_putendl(size);
		write(c->sock, size, ft_strlen(size));
		senddata(c, command);
	}
}
