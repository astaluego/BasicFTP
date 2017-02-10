/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <aderuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:40:32 by aderuell          #+#    #+#             */
/*   Updated: 2015/01/08 14:01:33 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*cur;

	if (n == 0)
		return (s);
	cur = (unsigned char *)s;
	while (n--)
	{
		*cur = (unsigned char)c;
		if (n)
			cur++;
	}
	return (s);
}
