/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <aderuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:38:39 by aderuell          #+#    #+#             */
/*   Updated: 2015/01/07 15:55:02 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcpy(char *dest, const char *src)
{
	int		i;
	int		max;

	i = 0;
	max = ft_strlen(src);
	while (i <= max)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
