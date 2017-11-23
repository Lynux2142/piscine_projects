/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:07:29 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/23 10:53:37 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"
#include <stdlib.h>

static int		ft_check_one(char *tab)
{
	int		i;
	int		count;

	i = 0;
	count = 1;
	while (tab[i])
	{
		if (tab[i] == '#' && count < 4)
		{
			if (tab[i + 1] == '#' && tab[i + 2] == '#' && tab[i + 5] == '#')
				return (1);
			if (tab[i + 1] != '#' && tab[i + 3] != '#'
					&& tab[i + 4] != '#' && tab[i + 5] != '#')
				return (0);
			++count;
			if (tab[i + 1] != '#' && tab[i + 4] != '#'
					&& tab[i + 5] != '#')
				return (0);
		}
		++i;
	}
	return (1);
}

static void		ft_split(char *tab, char **group, int len)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	k = 0;
	while (++i < len)
	{
		if (!(group[i] = (char *)malloc(sizeof(char) * 21)))
			return ;
		j = -1;
		while (++j < 20)
		{
			group[i][j] = tab[k];
			++k;
		}
		group[i][j] = '\0';
		++k;
	}
	group[i] = 0;
}

char			**ft_split_tetri(char *tab)
{
	char	**group;
	int		len;
	int		i;

	if ((len = ft_nb_tetri(tab)) > 26)
		return (0);
	if (!(group = (char **)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	ft_split(tab, group, len);
	i = -1;
	while (group[++i])
		if (!ft_check_one(group[i]))
			return (NULL);
	return (group);
}
