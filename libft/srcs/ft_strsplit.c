/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aderuell <aderuell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 18:09:31 by aderuell          #+#    #+#             */
/*   Updated: 2015/01/07 16:13:16 by aderuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdlib.h>

static int		ft_count_word(char const *s, char c)
{
	int			i;
	int			res;

	i = 0;
	res = 0;
	if (s[i] != c)
	{
		res = 1;
		i++;
	}
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i - 1] == c)
		{
			res++;
		}
		i++;
	}
	return (res);
}

static int		ft_count_letter(char const *s, char c, int i)
{
	int			tmp;

	tmp = 0;
	while (s[i] != c && s[i] != '\0')
	{
		tmp++;
		i++;
	}
	return (tmp);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	int			i;
	int			tmp;
	int			count;

	if (s == NULL)
		return (NULL);
	i = 0;
	count = 0;
	tab = (char **)malloc(sizeof(char*) * (ft_count_word(s, c) + 1));
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			tmp = ft_count_letter(s, c, i);
			tab[count] = ft_strsub(s, i, tmp);
			count++;
			i = i + tmp;
		}
		else
			i++;
	}
	tab[count] = NULL;
	return (tab);
}
