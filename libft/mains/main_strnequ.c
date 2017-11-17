/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strenqu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:10:09 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/16 12:25:57 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_print_result(int n)
{
	if (n == 0)
		write(1, "0", 1);
	else
		write(1, "1", 1);
}

int		main(int argc, const char *argv[])
{
	int	arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		if (ft_strnequ("salut", "salut", 50) == 1)
			ft_putstr("OK");
		else
			ft_putstr("KO");
	}
	else if (arg == 2)
	{
		if (ft_strnequ("test", "tests", 6) == 0)
			ft_putstr("OK");
		else
			ft_putstr("KO");
	}
	else if (arg == 3)
	{
		if (ft_strnequ("tests", "test", 6) == 0)
			ft_putstr("OK");
		else
			ft_putstr("KO");
	}
	else if (arg == 4)
	{
		if (ft_strnequ("test", "tEst", 6) == 0)
			ft_putstr("OK");
		else
			ft_putstr("KO");
	}
	else if (arg == 5)
	{
		if (ft_strnequ("", "test", 6) == 0)
			ft_putstr("OK");
		else
			ft_putstr("KO");
	}
	else if (arg == 6)
	{
		if (ft_strnequ("test", "", 6) == 0)
			ft_putstr("OK");
		else
			ft_putstr("KO");
	}
	else if (arg == 7)
	{
		if (ft_strnequ("", "", 6) == 1)
			ft_putstr("OK");
		else
			ft_putstr("KO");
	}
	else if (arg == 8)
	{
		if (ft_strnequ("test", "test", 2) == 1)
			ft_putstr("OK");
		else
			ft_putstr("KO");
	}
	else if (arg == 9)
	{
		if (ft_strnequ("tew", "tez", 2) == 1)
			ft_putstr("OK");
		else
			ft_putstr("KO");
	}
	else if (arg == 10)
	{
		if (ft_strnequ("", "", 0) == 1)
			ft_putstr("OK");
		else
			ft_putstr("KO");
	}
	else if (arg == 11)
	{
		if (ft_strnequ("abcd", "zxyw", 0) == 1)
			ft_putstr("OK");
		else
			ft_putstr("KO");
	}
	return (0);
}
