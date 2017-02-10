/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <aderuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 20:40:50 by aderuell          #+#    #+#             */
/*   Updated: 2015/01/07 17:40:26 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;

	if (alst == NULL)
		return ;
	while (*alst != NULL)
	{
		if (del != NULL)
			del((*alst)->content, (*alst)->content_size);
		tmp = *alst;
		*alst = (*alst)->next;
		free(tmp);
	}
	*alst = NULL;
}
