/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:49:24 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/24 10:30:51 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

int		ft_sr(int nb)
{
	int i;

	i = 0;
	while ((i * i) < (nb * 4))
		++i;
	return (i);
}

int		ft_nb_row(char *tab)
{
	int	i;
	int	row;

	i = -1;
	row = 0;
	while (tab[++i])
	{
		while (tab[i] != '\n')
			++i;
		++row;
	}
	return (row);
}

int		ft_nb_tetri(char *tab)
{
	int	i;
	int	row;

	i = -1;
	row = 0;
	while (tab[++i])
	{
		while (tab[i] != '\n')
			++i;
		++row;
	}
	return ((row + 1) / 5);
}
