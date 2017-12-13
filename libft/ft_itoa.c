/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 17:13:39 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/13 17:38:25 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		count_digits(int nbr)
{
	int result;

	if (nbr == 0)
		return (1);
	result = 0;
	while (nbr)
	{
		nbr /= 10;
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

static void		ft_calc(int nbr, char *nb, int size)
{
	int i;

	i = 0;
	if (nbr < 0)
	{
		nb[i] = '-';
		++i;
		++size;
	}
	nb[size] = '\0';
	--size;
	while (i <= size)
	{
		nb[size] = ft_abs(nbr % 10) + '0';
		nbr /= 10;
		--size;
	}
}

char			*ft_itoa(int nbr)
{
	char *nb;

	if (!(nb = (char *)malloc(sizeof(char) * count_digits(nbr))))
		return (NULL);
	ft_calc(nbr, nb, count_digits(nbr));
	return (nb);
}
