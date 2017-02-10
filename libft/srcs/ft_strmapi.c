/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <aderuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 19:22:23 by aderuell          #+#    #+#             */
/*   Updated: 2015/01/07 17:26:37 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dest;
	unsigned int	i;
	unsigned int	size;

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
			dest[i] = f(s[i], i);
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}
