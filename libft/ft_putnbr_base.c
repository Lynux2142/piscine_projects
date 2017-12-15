/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 10:34:25 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/15 12:36:02 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check(char *base)
{
	int i;

	if (ft_strlen(base) < 2 || ft_strlen(base) > 16)
		return (0);
	i = -1;
	while (base[++i])
		if (!ft_isalnum(base[i]))
			return (0);
	return (1);
}

void	ft_calc(int nbr, char *base, int i)
{
	if (nbr >= i || nbr <= -i)
	{
		ft_calc(nbr / i, base, i);
		ft_calc(nbr % i, base, i);
	}
	else if (nbr >= 0)
		ft_putchar(base[nbr]);
	else
		ft_putchar(base[-nbr]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (!ft_check(base))
		return ;
	if (nbr < 0 && ft_strlen(base) == 10)
		ft_putchar('-');
	ft_calc(nbr, base, ft_strlen(base));
	ft_putchar('\n');
}
