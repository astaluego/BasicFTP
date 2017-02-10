/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <aderuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/27 18:00:22 by aderuell          #+#    #+#             */
/*   Updated: 2015/03/13 18:19:36 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strjoin_char(char *s1, char c, char *s2)
{
	char		*str;
	size_t		lens1;
	size_t		lens2;

	if (s2 == NULL)
		return ((char *)s1);
	if (s1 == NULL)
		return ((char *)s2);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!str)
		return (NULL);
	ft_strcpy(str, s1);
	str[lens1] = c;
	ft_strcpy(str + lens1 + 1, s2);
	str[lens1 + lens2 + 2] = '\0';
	return (str);
}
