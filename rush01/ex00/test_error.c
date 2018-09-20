/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/16 10:21:36 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/13 12:33:53 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_argv_leng(char **str)
{
	int i;
	int j;

	i = 0;
	while (++i != 10)
	{
		j = 0;
		while (str[i][j] != '\0')
			j++;
		if (j != 9)
			return (0);
	}
	return (1);
}

int		ft_check_nbrs(char **argv)
{
	int i;
	int j;
	int counter;

	counter = 0;
	i = 0;
	while (++i < 10)
	{
		j = -1;
		while (++j < 9)
			if (argv[i][j] >= '1' && argv[i][j] <= '9')
				counter++;
	}
	if (counter >= 17)
		return (1);
	return (0);
}

int		ft_test_error(int argc, char **argv)
{
	int i;
	int j;

	if (argc != 10)
		return (0);
	if (ft_argv_leng(argv) == 0)
		return (0);
	i = 0;
	while (++i < 10)
	{
		j = -1;
		while (++j < 9)
		{
			if (argv[i][j] == '.')
				argv[i][j] = '0';
			else if (argv[i][j] <= '0' || argv[i][j] > '9')
				return (0);
		}
	}
	if (!ft_check_nbrs(argv))
		return (0);
	return (1);
}
