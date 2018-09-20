/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 14:59:25 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/22 19:22:32 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void				ft_calc(int nb)
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

void				ft_putnbr(int nb)
{
	if (nb < 0)
		ft_putchar('-');
	ft_calc(nb);
}

void				ft_show_tab(struct s_stock_par *par)
{
	int			i;
	int			j;
	int			k;

	i = 1;
	while (par[i].str != 0)
	{
		j = 0;
		while (par[i].copy[j] != '\0')
			ft_putchar(par[i].copy[j++]);
		ft_putchar('\n');
		ft_putnbr(par[i].size_param);
		ft_putchar('\n');
		j = 0;
		while (par[i].tab[j] != 0)
		{
			k = 0;
			while (par[i].tab[j][k] != '\0')
				ft_putchar(par[i].tab[j][k++]);
			ft_putchar('\n');
			++j;
		}
		++i;
	}
}
