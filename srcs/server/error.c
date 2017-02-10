/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:16:22 by aderuell          #+#    #+#             */
/*   Updated: 2016/04/25 15:16:25 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int						error(char *str)
{
	ft_putstr("Error : ");
	ft_putendl(str);
	exit(-1);
}

void					usage(char *str)
{
	ft_putstr("Usage : ");
	ft_putstr(str);
	ft_putendl(" <port 1234>");
	exit(-1);
}
