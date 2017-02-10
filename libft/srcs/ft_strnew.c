/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <aderuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 15:56:01 by aderuell          #+#    #+#             */
/*   Updated: 2015/03/11 16:27:23 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char		*ft_strnew(size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char *) * (n + 1));
	if (!str)
	{
		return (NULL);
	}
	ft_bzero(str, n);
	str[n] = '\0';
	return (str);
}
