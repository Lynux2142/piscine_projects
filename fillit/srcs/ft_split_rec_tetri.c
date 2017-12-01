/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_tetri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 14:07:29 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/01 12:32:56 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			if (tab[i + 1] != '#' && tab[i + 3] != '#' && tab[i + 4] != '#'
			&& tab[i + 5] != '#')
				return (0);
			if (tab[i + 1] != '#' && tab[i + 4] != '#' && tab[i + 5] != '#')
				return (0);
			++count;
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
}

static char		**ft_split_tetri(char *tab)
{
	char	**group;
	int		len;
	int		i;

	if ((len = ft_nb_tetri(tab)) > 26)
		return (NULL);
	if (!(group = (char **)ft_memalloc(sizeof(char *) * len)))
		return (NULL);
	ft_split(tab, group, len);
	i = -1;
	while (++i < len)
		if (!ft_check_one(group[i]))
		{
			if (group != NULL)
			{
				len = -1;
				while (++len <= i)
					ft_memdel((void *)&(group[len]));
				ft_memdel((void **)&group);
			}
			return (NULL);
		}
	return (group);
}

static t_list	*ft_id_one_tetri(char *tab, int index)
{
	int		i;
	int		q;
	int		*id;
	int		count;
	t_list	*tetris;

	i = -1;
	count = 1;
	if (!(id = (int *)ft_memalloc(sizeof(int) * 4)))
		return (NULL);
	id[0] = index;
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
	if (index == 0)
		tetris = ft_create_elem(id, 4);
	else
		ft_list_push_back(&tetris, id, 4);
	return (tetris);
}

t_list			*ft_split_rec_tetri(char *tab)
{
	char	**group;
	t_list	*tetris;
	int		i;
	int		len;

	len = ft_nb_tetri(tab);
	if (!(group = ft_split_tetri(tab)))
		return (NULL);
	i = -1;
	while (++i < len)
		if (!(tetris = ft_id_one_tetri(group[i], i)))
			return (NULL);
	if (group != NULL)
	{
		i = -1;
		while (++i < len)
			ft_memdel((void *)&(group[i]));
		ft_memdel((void **)&group);
	}
	return (tetris);
}
