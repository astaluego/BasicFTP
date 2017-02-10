/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <aderuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 14:12:14 by aderuell          #+#    #+#             */
/*   Updated: 2015/01/07 15:52:59 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	char	chr;

	chr = c;
	if (chr == '\0')
	{
		return ((char*)s + ft_strlen(s));
	}
	else if (*s == '\0')
	{
		return (0);
	}
	else if (*s == c)
	{
		return ((char*)s);
	}
	else
	{
		return (ft_strchr((char*)s + 1, c));
	}
}
