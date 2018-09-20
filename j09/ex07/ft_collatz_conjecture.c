/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 16:20:31 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/14 16:24:24 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_collatz1(unsigned int nb)
{
	unsigned int i;

	i = 1;
	if (nb != 1)
	{
		if ((nb % 2) == 0)
			i += ft_collatz1(nb / 2);
		else
			i += ft_collatz1(3 * nb + 1);
	}
	return (i);
}

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	unsigned int result;

	result = ft_collatz1(base) - 1;
	return (result);
}
