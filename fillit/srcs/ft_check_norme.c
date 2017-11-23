/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_norme.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:46:25 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/23 11:11:20 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"

static int	ft_check_number(char *tab)
{
	int		i;
	int		count;
	int		row;

	i = -1;
	count = 0;
	row = 0;
	while (tab[++i])
	{
		while (tab[i] != '\n')
		{
			if (tab[i] == '#')
				++count;
			++i;
		}
		++row;
		if (((row % 5) == 0 && tab[i - 1] == '\n') || row == ft_nb_row(tab))
		{
			if (count != 4)
				return (0);
			else
				count = 0;
		}
	}
	return (1);
}

int			ft_check_norme(char *tab)
{
	int		i;
	int		col;
	int		row;

	i = -1;
	row = 0;
	while (tab[++i])
	{
		col = 0;
		while (tab[i] != '\n')
		{
			if (tab[i] != '.' && tab[i] != '#')
				return (0);
			col++;
			++i;
		}
		row++;
		if ((row % 5 == 0 && tab[i - 1] != '\n')
				|| (tab[i] == '\n' && tab[i - 1] == '\n' && tab[i + 1] == '\n')
				|| (col != 4 && col != 0) || !(ft_check_number(tab)))
			return (0);
		else if (tab[i - 1] != '\n' && tab[i] == '\n' && tab[i + 1] == '\0')
			return (1);
	}
	return (0);
}
