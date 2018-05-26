/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 09:20:23 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/25 09:57:08 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_calc(int nb)
{
	if (nb >= 10 || nb <= -10)
	{
		ft_calc(nb / 10);
		ft_calc(nb % 10);
	}
	else if (nb >= 0)
		ft_putchar(nb + '0');
	else
		ft_putchar('0' - nb);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
		ft_putchar('-');
	ft_calc(nb);
}

void	ft_print_result(int result)
{
	ft_putnbr(result);
	ft_putchar('\n');
}
