/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <aderuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:25:23 by aderuell          #+#    #+#             */
/*   Updated: 2015/01/07 16:03:41 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_strlen(const char *string)
{
	size_t	i;

	i = 0;
	if (string == NULL)
	{
		return (0);
	}
	while (string[i] != '\0')
	{
		i++;
	}
	return (i);
}
