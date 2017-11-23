/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:49:24 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/23 11:12:08 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

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
