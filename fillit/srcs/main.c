/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:43:09 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/01 14:20:51 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <stdlib.h>

static int		ft_error(int erreur)
{
	ft_putstr("error\n");
	return (erreur);
}

void			ft_print_result(char **group, int len)
{
	int	i = -1;
	int	j = -1;

	j = -1;
	while (++j < len)
	{
		i = -1;
		while (++i < len)
			ft_putchar(group[j][i]);
		ft_putchar('\n');
	}
}

char			**ft_create_square(int len)
{
	char	**square;
	int		i;

	if (!(square = (char **)ft_memalloc(sizeof(char *) * len)))
		return (NULL);
	i = -1;
	while (++i < len)
	{
		if (!(square[i] = (char *)ft_memalloc(sizeof(char) * len)))
			return (NULL);
		ft_memset(square[i], '.', len);
	}
	return (square);
}

int				main(int ac, char **av)
{
	char	*tab;
	t_list	*tetris;
	t_list	*tmp;
	int		len;
	char	**grid;
	int		i;

	if (ac > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (0);
	}
	else if (ac < 2)
	{
		write(2, "File name missing.\n", 19);
		return (0);
	}
	if (!(tab = ft_stock_and_check_file(av[1])))
		return (ft_error(-1));
	if (!(tetris = ft_split_rec_tetri(tab)))
		return (ft_error(3));
	len = ft_sqrt(ft_listlen(tetris) * 4);
	grid = ft_create_square(len);
	if (ft_solve_grid(tetris, grid, len))
		ft_print_result(grid, len);
	i = -1;
	while (++i < len)
		ft_memdel((void *)&(grid[i]));
	ft_memdel((void **)&grid);
	ft_memdel((void *)&tab);
	while (tetris)
	{
		tmp = tetris;
		tetris = tetris->next;
		ft_memdel((void *)&tmp->content);
		ft_memdel((void *)&tmp);
	}
	ft_memdel((void *)&tetris);
	return (0);
}
