/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:44:10 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/16 15:48:48 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	ft_print_result(int n)
{
	char c;

	if (n >= 10)
		ft_print_result(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}

int		main(int argc, char **argv)
{
	char	*dest;
	char	*dest2;
	int		arg;

	if (argc != 2)
	{
		printf("un argument est requis !\n");
		return (1);
	}
	dest = ft_strnew(15);
	dest2 = ft_strnew(15);
	memset(dest, 0, 15);
	memset(dest, 'r', 6);
	memset(dest2, 0, 15);
	memset(dest2, 'r', 6);
	if ((arg = atoi(argv[1])) == 1)
	{
		dest[11] = 'a';
		ft_print_result(ft_strlcat(dest, "lorem", 15));
		write(1, "\n", 1);
		write(1, dest, 15);
		write(1, "\n", 1);
		dest2[11] = 'a';
		ft_print_result(strlcat(dest2, "lorem", 15));
		write(1, "\n", 1);
		write(1, dest2, 15);
	}
	else if (arg == 2)
	{
		ft_print_result(ft_strlcat(dest, "", 15));
		write(1, "\n", 1);
		write(1, dest, 15);
		write(1, "\n", 1);
		ft_print_result(strlcat(dest2, "", 15));
		write(1, "\n", 1);
		write(1, dest2, 15);
	}
	else if (arg == 3)
	{
		dest[0] = '\0';
		dest[11] = 'a';
		ft_print_result(ft_strlcat(dest, "lorem ipsum", 15));
		write(1, "\n", 1);
		write(1, dest, 15);
		write(1, "\n", 1);
		dest2[0] = '\0';
		dest2[11] = 'a';
		ft_print_result(strlcat(dest2, "lorem ipsum", 15));
		write(1, "\n", 1);
		write(1, dest2, 15);
	}
	else if (arg == 4)
	{
		dest[14] = 'a';
		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 15));
		write(1, "\n", 1);
		write(1, dest, 15);
		write(1, "\n", 1);
		dest2[14] = 'a';
		ft_print_result(strlcat(dest2, "lorem ipsum dolor sit amet", 15));
		write(1, "\n", 1);
		write(1, dest2, 15);
	}
	else if (arg == 5)
	{
		dest[10] = 'a';
		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 0));
		write(1, "\n", 1);
		write(1, dest, 15);
		write(1, "\n", 1);
		dest2[10] = 'a';
		ft_print_result(strlcat(dest2, "lorem ipsum dolor sit amet", 0));
		write(1, "\n", 1);
		write(1, dest2, 15);
	}
	else if (arg == 6)
	{
		dest[10] = 'a';
		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 1));
		write(1, "\n", 1);
		write(1, dest, 15);
		write(1, "\n", 1);
		dest2[10] = 'a';
		ft_print_result(strlcat(dest2, "lorem ipsum dolor sit amet", 1));
		write(1, "\n", 1);
		write(1, dest2, 15);
	}
	else if (arg == 7)
	{
		memset(dest, 'r', 15);
		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
		write(1, "\n", 1);
		write(1, dest, 15);
		write(1, "\n", 1);
		memset(dest2, 'r', 15);
		ft_print_result(strlcat(dest2, "lorem ipsum dolor sit amet", 5));
		write(1, "\n", 1);
		write(1, dest2, 15);
	}
	else if (arg == 8)
	{
		dest[10] = 'a';
		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 6));
		write(1, "\n", 1);
		write(1, dest, 15);
		write(1, "\n", 1);
		dest2[10] = 'a';
		ft_print_result(strlcat(dest2, "lorem ipsum dolor sit amet", 6));
		write(1, "\n", 1);
		write(1, dest2, 15);
	}
	return (0);
}
