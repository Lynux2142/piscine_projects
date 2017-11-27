/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 08:31:00 by manki             #+#    #+#             */
/*   Updated: 2017/11/27 16:00:50 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"
#include <stdlib.h>

static void		ft_decrypt(int *id, t_coord **c, t_coord *g)
{
	int		i;

	i = 0;
	c[i]->x = g->x;
	c[i]->y = g->y;
	while (++i < 4)
	{
		c[i]->x = c[i - 1]->x;
		c[i]->y = c[i - 1]->y;
		if (id[i] == 1)
			c[i]->x += 1;
		else if (id[i] == 3)
		{
			c[i]->y += 1;
			c[i]->x -= 2;
		}
		else if (id[i] == 4)
		{
			c[i]->y += 1;
			c[i]->x -= 1;
		}
		else if (id[i] == 5)
			c[i]->y += 1;
	}
}

static t_coord	**ft_coord_alloc(int nb)
{
	t_coord		**c;
	int			i;

	if (!(c = ft_memalloc(sizeof(t_coord *) * nb)))
		return (NULL);
	i = -1;
	while (++i < 4)
		if (!(c[i] = ft_memalloc(sizeof(t_coord) * 4)))
			return (NULL);
	return (c);
}

static void		ft_free_c(t_coord **c)
{
	int		i;

	i = -1;
	while (++i < 4)
		ft_memdel((void *)&c[i]);
	ft_memdel((void *)&c);
	c = NULL;
}

static t_bool	ft_fill_one(int *id, char **grid, t_coord *g, char *tab, int len)
{
	t_coord		**c;
	int			i;

	if (!(c = ft_coord_alloc(ft_nb_tetri(tab))))
		return (0);
	ft_decrypt(id, c, g);
	i = -1;
	while (++i < 4)
		if (c[i]->x >= len || c[i]->y >= len || grid[c[i]->y][c[i]->x] != '.')
		{
			ft_free_c(c);
			return (0);
		}
	i = -1;
	while (++i < 4)
		grid[c[i]->y][c[i]->x] = id[0] + 'A';
	ft_free_c(c);
	return (1);
}

t_bool			ft_solve_grid(int **id, char *tab, int len, char **grid)
{
	int		i;
	t_coord g;

	i = 0;
	g.y = 0;
	while (i < ft_nb_tetri(tab) && g.y < len)
	{
		g.x = 0;
		while (i < ft_nb_tetri(tab) && g.x < len)
		{
			if (i < ft_nb_tetri(tab) && ft_fill_one(id[i], grid, &g, tab, len))
			{
				g.y = 0;
				g.x = 0;
				i++;
			}
			g.x++;
		}
		g.y++;
	}
	return (i);
}
