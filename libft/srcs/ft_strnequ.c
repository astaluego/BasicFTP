/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <aderuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 20:10:29 by aderuell          #+#    #+#             */
/*   Updated: 2015/01/07 16:08:30 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		i;

	if (s1 != NULL && s2 != NULL)
	{
		i = (ft_strncmp(s1, s2, n) ? 0 : 1);
		return (i);
	}
	return (0);
}
