/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:17:21 by aderuell          #+#    #+#             */
/*   Updated: 2016/04/25 15:18:12 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void					normalize(char *str)
{
	int					i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 9 || str[i] == 11)
			str[i] = ' ';
		i = i + 1;
	}
}

void					freetab(char **tab)
{
	int					i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab[i]);
	tab[i] = NULL;
	free(tab);
	tab = NULL;
}
