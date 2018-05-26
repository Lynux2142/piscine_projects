/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 16:30:23 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/09 17:33:22 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_print(int a, int b)
{
	int w;
	int x;
	int y;
	int z;

	w = '0' + (a / 10);
	x = '0' + (a % 10);
	y = '0' + (b / 10);
	z = '0' + (b % 10);
	if ((a != b) && (a < b))
	{
		ft_putchar(w);
		ft_putchar(x);
		ft_putchar(' ');
		ft_putchar(y);
		ft_putchar(z);
		if ((a != 98) || (b != 99))
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
	return (0);
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	while (a <= 98)
	{
		b = 1;
		while (b <= 99)
		{
			ft_print(a, b);
			b++;
		}
		a++;
	}
}
