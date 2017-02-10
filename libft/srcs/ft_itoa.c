/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 15:02:10 by aderuell          #+#    #+#             */
/*   Updated: 2015/01/07 15:03:41 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static char		*ft_putnbr_in_char(int n, int size, char *nbr)
{
	if (n < 0)
	{
		nbr[0] = '-';
		return (ft_putnbr_in_char(n * (-1), size, nbr));
	}
	if (n >= 10)
	{
		nbr[size] = (n % 10) + '0';
		return (ft_putnbr_in_char(n / 10, size - 1, nbr));
	}
	nbr[size] = n + '0';
	return (nbr);
}

static int		ft_numlen(int n)
{
	if (n < 0)
		return (ft_numlen(n * -1) + 1);
	if (n >= 10)
		return (ft_numlen(n / 10) + 1);
	return (1);
}

char			*ft_itoa(int n)
{
	char		*tab;
	int			tmp;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp = ft_numlen(n);
	tab = ft_strnew(tmp);
	return (ft_putnbr_in_char(n, tmp - 1, tab));
}
