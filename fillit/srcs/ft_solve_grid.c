/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 08:31:00 by manki             #+#    #+#             */
/*   Updated: 2017/12/01 13:32:21 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static void		ft_decrypt(t_list *tetris, t_coord **c, t_coord *g)
{
	int		i;
	int		*id;

	i = 0;
	id = tetris->content;
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

	if (!(c = (t_coord **)ft_memalloc(sizeof(t_coord *) * nb)))
		return (NULL);
	i = -1;
	while (++i < 4)
		if (!(c[i] = (t_coord *)ft_memalloc(sizeof(t_coord) * 4)))
			return (NULL);
	return (c);
}

static void		ft_free_c(t_coord **c)
{
	int		i;

	i = -1;
	while (++i < 4)
		ft_memdel((void *)&(c[i]));
	ft_memdel((void **)&c);
	c = NULL;
}

static t_bool	ft_fill_one(t_list *tetris, char **grid, t_coord *g, int len)
{
	t_coord		**c;
	int			i;
	int			*id;

	if (!(c = ft_coord_alloc(ft_listlen(tetris))))
		return (0);
	ft_decrypt(tetris, c, g);
	i = -1;
	while (++i < 4)
		if (c[i]->x >= len || c[i]->y >= len || grid[c[i]->y][c[i]->x] != '.')
		{
			ft_free_c(c);
			return (0);
		}
	id = tetris->content;
	i = -1;
	while (++i < 4)
		grid[c[i]->y][c[i]->x] = id[0] + 'A';
	ft_free_c(c);
	return (1);
}

static t_bool		ft_increment_g(t_coord *g, int grid_len)
{
	if (g->y + 1 < grid_len)
	{
		if (g->x + 1 < grid_len)
			g->x++;
		else
		{
			g->x = 0;
			g->y++;
		}
		return (1);
	}
	else
		return (0);
}

static void		ft_remove_last(char **grid, int len, int index, t_coord *g)
{
	int		i;

	i = 0;
	g->y = len - 1;
	while (i < 4 && g->y >= 0)
	{
		g->x = len - 1;
		while (i < 4 && g->x >= 0)
		{
			if (grid[g->y][g->x] == 'A' + index)
			{
				grid[g->y][g->x] = '.';
				i++;
			}
			g->x--;
		}
		g->y--;
	}
	g->y++;
	g->x++;
	ft_increment_g(g, len);
}

static int			ft_resolve_grid(t_list *tetris, char **grid, int len, t_coord *g)
{
	int		*id;

	if (!tetris)
	{
		ft_memdel((void *)&id);
		return (1);
	}
	if ((g->y < len) && (g->x < len))
	{
		if (ft_fill_one(tetris, grid, g, len))
		{
			g->x = 0;
			g->y = 0;
			ft_print_result(grid, len);
			ft_putchar('\n');
			if (ft_resolve_grid(tetris->next, grid, len, g))
				return (1);
			else
			{
				id = tetris->content;
				ft_remove_last(grid, len, id[0], g);
				ft_print_result(grid, len);
				ft_putchar('\n');
				return (ft_resolve_grid(tetris, grid, len, g));
			}
		}
		else
		{
			if (!ft_increment_g(g, len))
				return (0);
			return (ft_resolve_grid(tetris, grid, len, g));
		}
	}
	return (0);
}

t_list				*ft_solve_grid(t_list *tetris, char **grid, int len)
{
	t_coord		g;
	t_list		*tmp;
	int			i;

	g.x = 0;
	g.y = 0;
	tmp = tetris;
	while (ft_resolve_grid(tmp, grid, len, &g) == 0)
	{
		++len;
		i = -1;
		while (grid[i])
			ft_memdel((void *)&(grid[i]));
		ft_memdel((void **)&(grid));
		grid = ft_create_square(len);
	}
	return (tmp);
}
