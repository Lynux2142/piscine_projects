/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:21:37 by manki             #+#    #+#             */
/*   Updated: 2017/11/24 14:31:23 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"
#include <stdlib.h>

char		**ft_create_grid(int len)
{
	char	**grid;
	int		i;

	if (!(grid = (char **)malloc(sizeof(char *) * len)))
		return (NULL);
	i = -1;
	while (++i < len)
	{
		if (!(grid[i] = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		ft_bzero(grid[i], len + 1);
	}
	grid[i] = 0;
	return (grid);
}

static void	ft_decrypt(int id, int *i, int *j)
{
	if (id == 1)
		*i += 1;
	if (id == 3)
	{
		*j += 1;
		*i -= 2;
	}
	if (id == 4)
	{
		*j += 1;
		*i -= 1;
	}
	if (id == 5)
		*j += 1;
}

static int	ft_fill_one(int *id, char **grid, int len)
{
	int		*i;
	int		*j;
	int		k;

	if (!(i = (int *)malloc(sizeof(int))))
		return (0);
	if (!(j = (int *)malloc(sizeof(int))))
		return (0);
	i = 0;
	j = 0;
	k = -1;
	while (id[++k])
	{
		ft_decrypt(id[k], i, j);
		if (grid[*i][*j] != '.')
			return (0);
		grid[*i][*j] = id[0] + 'A';
	}
	free(i);
	free(j);
	return (1);
}

int			ft_solve_grid(int **id, int len)
{
	int		i;
	char	**grid;

	if (!(grid = ft_create_grid(len)))
		return (-1);
	i = -1;
	while (id[++i])
		ft_fill_one(id[i], grid, len);
	ft_create_grid(len + 1);
	return (0);
}
