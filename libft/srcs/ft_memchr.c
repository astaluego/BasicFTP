/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <aderuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:47:56 by aderuell          #+#    #+#             */
/*   Updated: 2015/01/07 15:41:57 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memchr(const void *s, int c, size_t n)
{
	char	*src;

	src = (char*)s;
	while (n--)
	{
		if (*(unsigned char*)src == (unsigned char)c)
		{
			return (src);
		}
		src++;
	}
	return (NULL);
}
