/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <aderuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 19:39:53 by aderuell          #+#    #+#             */
/*   Updated: 2015/01/07 15:57:19 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strequ(char const *s1, char const *s2)
{
	int		i;

	if (s1 != NULL && s2 != NULL)
	{
		i = (ft_strcmp(s1, s2) ? 0 : 1);
		return (i);
	}
	return (0);
}
