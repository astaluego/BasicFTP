/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 17:19:26 by aderuell          #+#    #+#             */
/*   Updated: 2015/01/07 17:30:32 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list			*map;
	t_list			*add;
	t_list			*tmp;

	if (f == NULL || lst == NULL)
		return (NULL);
	map = f(lst);
	tmp = map;
	lst = lst->next;
	while (lst != NULL)
	{
		add = f(lst);
		if (add == NULL)
		{
			return (NULL);
		}
		tmp->next = add;
		tmp = add;
		lst = lst->next;
	}
	return (map);
}
