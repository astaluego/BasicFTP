/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <aderuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 21:02:38 by aderuell          #+#    #+#             */
/*   Updated: 2015/01/07 15:38:22 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstiter(t_list *lst, void (*f)(t_list	*elem))
{
	t_list	*tmp;

	if (lst)
	{
		tmp = lst;
		while (tmp->next != NULL)
		{
			f(tmp);
			tmp = tmp->next;
		}
		f(tmp);
	}
}
