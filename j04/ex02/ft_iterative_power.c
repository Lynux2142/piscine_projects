/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 18:22:27 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/11 14:55:55 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int nb_init;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	nb_init = nb;
	while (power != 1)
	{
		nb = nb * nb_init;
		power--;
	}
	return (nb);
}
