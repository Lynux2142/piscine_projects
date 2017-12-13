/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:40:11 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/13 17:49:08 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		count_digits(int nbr, int base)
{
	int result;

	if (nbr == 0)
		return (1);
	result = 0;
	while (nbr)
	{
		nbr /= base;
		++result;
	}
	return (result);
}

static int		ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	else
		return (nbr);
}

static void		ft_calc(int nbr, char *nb, int size, int base)
{
	int i;

	i = 0;
	if (nbr < 0 && base == 10)
	{
		nb[i] = '-';
		++i;
		++size;
	}
	nb[size] = '\0';
	--size;
	while (i <= size)
	{
		if (ft_abs(nbr % base) > 9)
			nb[size] = ft_abs(nbr % base) + 'A' - 10;
		else
			nb[size] = ft_abs(nbr % base) + '0';
		nbr /= base;
		--size;
	}
}

char			*ft_itoa_base(int value, int base)
{
	char *nb;

	if (base < 2 || base > 16)
		return (NULL);
	if (!(nb = (char *)malloc(sizeof(char) * count_digits(value, base))))
		return (NULL);
	ft_calc(value, nb, count_digits(value, base), base);
	return (nb);
}
