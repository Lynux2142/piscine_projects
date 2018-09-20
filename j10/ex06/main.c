/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 08:29:58 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/26 17:31:09 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	if (argc == 4 && ((argv[2][0] != '+' && argv[2][0] != '-'
	&& argv[2][0] != '*' && argv[2][0] != '/' && argv[2][0] != '%')
	|| argv[2][1] != '\0'))
		write(1, "0\n", 2);
	else if (argc == 4 && argv[2][0] == '+')
		ft_plus(ft_atoi(argv[1]), ft_atoi(argv[3]));
	else if (argc == 4 && argv[2][0] == '-')
		ft_minus(ft_atoi(argv[1]), ft_atoi(argv[3]));
	else if (argc == 4 && argv[2][0] == '*')
		ft_multiply(ft_atoi(argv[1]), ft_atoi(argv[3]));
	else if (argc == 4 && argv[2][0] == '/')
	{
		if (ft_atoi(argv[3]) != 0)
			ft_divide(ft_atoi(argv[1]), ft_atoi(argv[3]));
		else
			write(1, "Stop : division by zero\n", 24);
	}
	else if (argc == 4 && argv[2][0] == '%')
	{
		if (ft_atoi(argv[3]) != 0)
			ft_modulo(ft_atoi(argv[1]), ft_atoi(argv[3]));
		else
			write(1, "Stop : modulo by zero\n", 22);
	}
	return (0);
}
