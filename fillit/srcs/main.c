/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:43:09 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/23 14:24:54 by lguiller         ###   ########.fr       */
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

int				main(int ac, char **av)
{
	char	*tab;
	char	**group;
	int		i;
	int		**id;
	int		j;

	if (ac > 2)
		write(2, "Too many arguments.\n", 20);
	else if (ac < 2)
		write(2, "tab name missing.\n", 19);
	if (!(tab = ft_stock_file(av[1])))
		return (ft_error(-1));
	if (!ft_check_norme(tab))
		return (ft_error(1));
	if (!(group = ft_split_tetri(tab)))
		return (ft_error(2));
	if (!(id = ft_register_tetri(tab, group)))
		return (ft_error(3));
	j = -1;
	while (++j < ft_nb_tetri(tab))
	{
		i = -1;
		while (++i < 4)
		{
			ft_putchar('|');
			if (i == 0)
				ft_putchar(id[j][i]);
			else
				ft_putchar(id[j][i] + '0');
			ft_putchar('|');
			if (i < 3)
				ft_putstr(" - ");
		}
		ft_putstr("\n");
	}
	free(id);
	free(group);
	free(tab);
	return (0);
}
