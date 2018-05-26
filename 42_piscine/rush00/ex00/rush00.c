/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 15:54:46 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/09 15:58:51 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	display(int *tab, char f, char e, char m)
{
	if (tab[1] == 1)
	{
		ft_putchar(f);
	}
	else if (tab[1] == tab[0])
	{
		ft_putchar(e);
	}
	else
	{
		ft_putchar(m);
	}
}

void	rush(int x, int y)
{
	int i;
	int d;
	int tab[2];

	if (x <= 0 || y <= 0)
		return ;
	i = 1;
	while (i <= y)
	{
		d = 1;
		while (d <= x)
		{
			tab[0] = x;
			tab[1] = d;
			if (i == 1)
				display(&tab[0], 'o', 'o', '-');
			else if (i == y)
				display(&tab[0], 'o', 'o', '-');
			else
				display(&tab[0], '|', '|', ' ');
			d++;
		}
		ft_putchar('\n');
		i++;
	}
}
