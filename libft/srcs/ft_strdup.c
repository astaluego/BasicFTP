/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <aderuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 19:05:07 by aderuell          #+#    #+#             */
/*   Updated: 2015/01/07 15:56:39 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*pointer;

	if (s1 != NULL)
	{
		pointer = (char *)malloc(sizeof(*pointer) * (ft_strlen(s1) + 1));
		if (pointer == NULL)
		{
			return (NULL);
		}
		else
		{
			ft_strcpy(pointer, s1);
			return (pointer);
		}
	}
	return (NULL);
}
