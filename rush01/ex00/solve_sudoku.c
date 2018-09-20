/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_sudoku.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 10:52:00 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/13 12:21:31 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_print(char **argv);

int		test_line(char **argv, int line, char value)
{
	int i;

	i = -1;
	while (++i < 9)
		if (argv[line][i] == value)
			return (0);
	return (1);
}

int		test_col(char **argv, int col, char value)
{
	int i;

	i = 0;
	while (++i < 10)
		if (argv[i][col] == value)
			return (0);
	return (1);
}

int		test_block(char **argv, int line, int col, char value)
{
	int block_h;
	int block_v;

	block_h = (line % 3) == 0 ? (line - 2) : (line - (line % 3)) + 1;
	block_v = col - (col % 3);
	line = block_h;
	col = block_v;
	while (line < (block_h + 3))
	{
		col = block_v - 1;
		while (++col < (block_v + 3))
			if (argv[line][col] == value)
				return (0);
		line++;
	}
	return (1);
}

int		solve_sudoku(char **sudoku, int line, int col)
{
	char vcl[3];

	if (line == 10 && col == 0)
		return (1);
	if (sudoku[line][col] != '0')
	{
		vcl[1] = (col < 8) ? col + 1 : 0;
		vcl[2] = (col < 8) ? line : line + 1;
		return (solve_sudoku(sudoku, vcl[2], vcl[1]));
	}
	vcl[0] = '0';
	while (vcl[0]++ < '9')
	{
		if (test_line(sudoku, line, vcl[0]) && test_col(sudoku, col, vcl[0])
		&& test_block(sudoku, line, col, vcl[0]))
		{
			sudoku[line][col] = vcl[0];
			vcl[1] = (col < 8) ? (col + 1) : (0);
			vcl[2] = (col < 8) ? (line) : (line + 1);
			if (solve_sudoku(sudoku, vcl[2], vcl[1]))
				return (1);
		}
	}
	sudoku[line][col] = '0';
	return (0);
}
