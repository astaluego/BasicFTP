/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:23:44 by aderuell          #+#    #+#             */
/*   Updated: 2016/04/25 15:23:46 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void					usage(char *str)
{
	ft_putstr("Usage : ");
	ft_putstr(str);
	ft_putendl(" <addr> <port 1234>");
	exit(-1);
}

int						error(char *str)
{
	ft_putstr("Error : ");
	ft_putendl(str);
	exit(-1);
}
