/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test20.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 10:50:03 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/16 08:41:31 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base);

int		main(int argc, char **argv)
{
	(void)argc;
	ft_putnbr_base(atoi(argv[1]), argv[2]);
	return (0);
}
