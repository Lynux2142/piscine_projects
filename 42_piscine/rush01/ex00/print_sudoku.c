/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sudoku.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 10:28:29 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/13 12:29:07 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char **argv)
{
	int		j;
	int		i;

	j = 0;
	i = 1;
	write(1, "\n", 1);
	while (i != 10)
	{
		j = 0;
		while (j != 9)
		{
			if (j == 3 || j == 6)
				write(1, "   ", 3);
			if ((i == 4 || i == 7) && j == 0)
				write(1, "\n", 1);
			write(1, &argv[i][j], 1);
			if (j == 8)
				write(1, "\n", 1);
			else
				write(1, " ", 1);
			j++;
		}
		i++;
	}
}
