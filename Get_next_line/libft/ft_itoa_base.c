/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:42:56 by exam              #+#    #+#             */
/*   Updated: 2017/12/12 12:32:54 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		nb_count(int value, int base)
{
	int nb;

	nb = 0;
	while (value)
	{
		value /= base;
		++nb;
	}
	return (nb);
}

int		ft_abs(int nb)
{
	nb < 0 ? nb *= -1 : nb;
	return (nb);
}

char	*ft_calc_pos(char *nb, int value, int base)
{
	int i;

	i = nb_count(value, base) - 1;
	nb[i + 1] = '\0';
	while (value)
	{
		if (ft_abs(value % base) > 9)
			nb[i] = (ft_abs(value % base) + 'A') - 10;
		else
			nb[i] = ft_abs(value % base) + '0';
		value /= base;
		--i;
	}
	return (nb);
}

char	*ft_calc_neg(char *nb, int value, int base)
{
	int i;

	i = nb_count(value, base);
	nb[i + 1] = '\0';
	nb[0] = '-';
	while (value)
	{
		if (ft_abs(value % base) > 9)
			nb[i] = (ft_abs(value % base) + 'A') - 10;
		else
			nb[i] = ft_abs(value % base) + '0';
		value /= base;
		--i;
	}
	return (nb);
}

char	*ft_itoa_base(int value, int base)
{
	char *nb;

	if (base < 2 || base > 16)
		return (NULL);
	if (base != 10)
		value = ft_abs(value);
	if (value < 0 && (value != -2147483648 || base == 10))
	{
		if (!(nb = (char *)malloc(sizeof(char) * (nb_count(value, base) + 1))))
			return (NULL);
		ft_calc_neg(nb, value, base);
	}
	else
	{
		if (!(nb = (char *)malloc(sizeof(char) * (nb_count(value, base) + 2))))
			return (NULL);
		ft_calc_pos(nb, value, base);
	}
	return (nb);
}
