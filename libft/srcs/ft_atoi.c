/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 14:51:48 by aderuell          #+#    #+#             */
/*   Updated: 2015/03/09 17:36:04 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *nb)
{
	int		res;
	int		sign;

	res = 0;
	sign = 1;
	while (ft_iswhite(*nb))
		nb++;
	if (*nb == '-')
	{
		sign = (-1);
		nb++;
	}
	else if (*nb == '+')
		nb++;
	while (*nb >= '0' && *nb <= '9')
		res = res * 10 + (*(nb++) - '0');
	return (sign * res);
}
