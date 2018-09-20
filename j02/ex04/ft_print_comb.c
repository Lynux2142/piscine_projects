/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 13:38:24 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/08 12:04:49 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print(char a, char b, char c)
{
	int x;
	int y;
	int z;

	x = '0' + a;
	y = '0' + b;
	z = '0' + c;
	ft_putchar(x);
	ft_putchar(y);
	ft_putchar(z);
	if (x < ('0' + 7))
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	int a;
	int b;
	int c;

	a = 0;
	while (a < 10)
	{
		b = 1;
		while (b < 10)
		{
			c = 2;
			while (c < 10)
			{
				if (((a != b) && (a != c) && (b != c)) && ((a < b) && (b < c)))
				{
					ft_print(a, b, c);
				}
				c++;
			}
			b++;
		}
		a++;
	}
}
