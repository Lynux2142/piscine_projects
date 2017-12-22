/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:42:33 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/06 16:03:22 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_iterative_factorial(int nb)
{
	int result;

	if (nb < 0 || nb > 12)
		return (0);
	result = 1;
	while (nb > 0)
	{
		result *= nb;
		--nb;
	}
	return (result);
}
