/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:43:09 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/27 14:50:18 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"
#include <unistd.h>
#include <stdlib.h>

static int		ft_error(int erreur)
{
	ft_putstr("error\n");
	return (erreur);
}

static void		ft_print_result(char **group, int len)
{
	int		i;
	int		j;

	j = -1;
	while (++j < len)
	{
		i = -1;
		while (++i < len)
			ft_putchar(group[j][i]);
		ft_putchar('\n');
	}
}

static char		**ft_create_square(int len)
{
	char	**square;
	int		i;

	if (!(square = (char **)malloc(sizeof(char *) * len)))
		return (NULL);
	i = -1;
	while (++i < len)
	{
		if (!(square[i] = (char *)malloc(sizeof(char) * len)))
			return (NULL);
		ft_memset(square[i], '.', len);
	}
	return (square);
}

int				main(int ac, char **av)
{
	char	*tab;
	int		**id;
	int		len;
	char	**grid;
	int		i;
	int		j;

	if (ac > 2)
		write(2, "Too many arguments.\n", 20);
	else if (ac < 2)
		write(2, "tab name missing.\n", 19);
	if (!(tab = ft_stock_and_check_file(av[1])))
		return (ft_error(-1));
	if (!(id = ft_split_rec_tetri(tab)))
		return (ft_error(3));
	i = 0;
	len = ft_sqrt(ft_nb_tetri(tab) * 4);
	while (i < ft_nb_tetri(tab))
	{
		if (!(grid = ft_create_square(len)))
			return (ft_error(4));
		if ((i = ft_solve_grid(id, tab, len, grid)) < ft_nb_tetri(tab))
		{
			j = -1;
			if (grid != NULL)
			{
			while (++j < len)
				ft_memdel((void *)&grid[j]);
			ft_memdel((void *)&grid);
			}
			len += 1;
		}
	}
	if (grid)
		ft_print_result(grid, len);
	i = -1;
	while (++i < len)
		ft_memdel((void *)&grid[i]);
	ft_memdel((void *)&grid);
	i = -1;
	while (++i < ft_nb_tetri(tab))
		ft_memdel((void *)&id[i]);
	ft_memdel((void *)&id);
	ft_memdel((void *)&tab);
	return (0);
}
