/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lynux <lguiller@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 20:04:33 by lynux             #+#    #+#             */
/*   Updated: 2017/08/09 20:24:05 by lynux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(void)
{
	int lol;

	lol = 1386950;
	ft_putnbr(lol);
	ft_putchar('\n');
	return (0);
}
