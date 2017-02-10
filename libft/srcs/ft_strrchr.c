/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <aderuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:45:27 by aderuell          #+#    #+#             */
/*   Updated: 2015/01/07 16:12:09 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	chr;
	int		max;

	chr = c;
	max = ft_strlen(s);
	if (chr == '\0')
	{
		return ((char*)s + ft_strlen(s));
	}
	while (max >= 0)
	{
		if (s[max] == c)
		{
			return ((char*)s + max);
		}
		max--;
	}
	return (NULL);
}
