/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 10:34:25 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/16 08:50:01 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

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
	int i;

	i = 0;
	while (base[i] != '\0')
		i++;
	if (nbr < 0)
		ft_putchar('-');
	ft_calc(nbr, base, i);
}
