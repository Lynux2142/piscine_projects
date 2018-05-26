/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 16:06:34 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/19 11:13:48 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi(char *str)
{
	int i;
	int negativ;
	int nb;

	i = 0;
	negativ = 0;
	nb = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
			|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == 45)
		negativ = 1;
	if ((str[i] == 45) || (str[i] == 43))
		i++;
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		nb *= 10;
		nb += ((int)str[i] - 48);
		i++;
	}
	if (negativ == 1)
		return (-nb);
	else
		return (nb);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

int		ft_base_to_num(char *nbr, char *base_from)
{
	int *new_nbr;
	int i;
	int j;
	int base_size;

	base_size = 0;
	while (base_from[base_size] != '\0')
		++base_size;
	i = 0;
	while (nbr[i] != '\0')
	{
		j = 0;
		while (base_from[j] != '\0')
		{
			if (nbr[i] == base_from[j])
			{
			}
			++j;
		}
		++i;
	}
	return (0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char *result;

	ft_base_to_num(nbr, base_from);
	return (result);
}
