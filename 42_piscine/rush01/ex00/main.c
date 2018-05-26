/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 09:08:34 by lguiller          #+#    #+#             */
/*   Updated: 2018/05/26 13:10:07 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

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
