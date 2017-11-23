/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_register_tetri.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 08:19:24 by manki             #+#    #+#             */
/*   Updated: 2017/11/23 14:24:52 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"
#include <stdlib.h>

static void	ft_fill_one_tetri(char *tab, int *id, int index)
{
	int		i;
	int		q;
	int		count;

	i = -1;
	count = 1;
	id[0] = index + 'A';
	while (tab[++i] && count < 4)
	{
		q = 1;
		while (tab[i] == '#' && tab[i + q] != '#')
			q++;
		if (tab[i] == '#')
		{
			id[count] = q;
			count++;
		}
	}
}

int			**ft_register_tetri(char *tab, char **group)
{
	int		**id;
	int		i;
	int		len;

	len = ft_nb_tetri(tab);
	if (!(id = (int **)malloc(sizeof(int *) * len)))
		return (NULL);
	i = -1;
	while (++i < len)
	{
		if (!(id[i] = (int *)malloc(sizeof(int) * 4)))
			return (NULL);
	}
	i = 0;
	while (i < len)
	{
		ft_fill_one_tetri(group[i], id[i], i);
		i++;
	}
	return (id);
}
