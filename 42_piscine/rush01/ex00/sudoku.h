/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:07:40 by lguiller          #+#    #+#             */
/*   Updated: 2018/05/26 13:10:48 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

# include <stdlib.h>
# include <unistd.h>

int		ft_test_error(int argc, char **argv);
void	ft_print(char **argv);
int		solve_sudoku(char **argv, int line, int column);

#endif
