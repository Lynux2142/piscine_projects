/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 09:08:34 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/16 18:44:20 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		ft_test_error(int argc, char **argv);

void	ft_print(char **argv);

int		solve_sudoku(char **argv, int line, int column);

int		main(int argc, char **argv)
{
	if (!ft_test_error(argc, argv))
	{
		write(1, "Error\n", 6);
	}
	else
	{
		if (solve_sudoku(argv, 1, 0) == 1)
		{
			solve_sudoku(argv, 1, 0);
			ft_print(argv);
		}
		else
			write(1, "Error\n", 6);
	}
	return (0);
}
