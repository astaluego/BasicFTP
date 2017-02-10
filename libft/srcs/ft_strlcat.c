/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <aderuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:54:12 by aderuell          #+#    #+#             */
/*   Updated: 2015/01/07 16:03:10 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	int		index;

	index = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	while (*dst)
		dst++;
	while (size - dst_len - index++ && *src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	dst[(-1) * ((size <= dst_len + src_len))] = '\0';
	return (dst_len + src_len);
}
