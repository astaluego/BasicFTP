/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <aderuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:20:29 by aderuell          #+#    #+#             */
/*   Updated: 2015/01/08 15:07:59 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*dest_char;
	const unsigned char	*src_char;

	i = 0;
	dest_char = dest;
	src_char = src;
	while (i < n)
	{
		dest_char[i] = src_char[i];
		if (src_char[i] == (unsigned char)c)
			return ((char*)(&dest_char[i + 1]));
		i++;
	}
	return (0);
}
