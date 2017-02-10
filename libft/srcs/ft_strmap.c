/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <aderuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 17:17:27 by aderuell          #+#    #+#             */
/*   Updated: 2015/01/07 16:04:29 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*dest;
	int		i;
	int		size;

	size = (int)ft_strlen(s);
	i = 0;
	dest = (char *)malloc(sizeof(char *) * ft_strlen(s));
	if (f == NULL || s == NULL)
	{
		return (NULL);
	}
	if (s[i] != '\0')
	{
		while (i < size)
		{
			dest[i] = f(s[i]);
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}
