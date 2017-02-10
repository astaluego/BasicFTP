/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <aderuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:02:04 by aderuell          #+#    #+#             */
/*   Updated: 2015/01/07 16:11:28 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(s2) == 0)
	{
		return ((char*)s1);
	}
	while (i < n && s1[i] != '\0')
	{
		j = 0;
		while (((i + j) < n) && s1[i + j] == s2[j])
		{
			j++;
			if (s2[j] == '\0')
			{
				return ((char*)s1 + i);
			}
		}
		i++;
	}
	return (NULL);
}
