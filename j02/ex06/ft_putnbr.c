/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 13:24:59 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/11 13:25:08 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

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
