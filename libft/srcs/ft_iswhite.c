/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 17:46:42 by aderuell          #+#    #+#             */
/*   Updated: 2015/01/07 19:19:25 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iswhite(int c)
{
	if (c == 9 || c == 10 || c == 11 || c == 12 || c == 32
			|| c == 13)
		return (1);
	return (0);
}
