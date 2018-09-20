/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 19:14:19 by exam              #+#    #+#             */
/*   Updated: 2017/07/27 09:52:01 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);	
}

void	repeat_alpha(char *str)
{
	int tab[2];

	tab[0] = 0;
	while (str[tab[0]] != '\0')
	{
		if (str[tab[0]] >= 'a' && str[tab[0]] <= 'z')
		{
			tab[1] = str[tab[0]] - ('a' - 1);
			while (tab[1] != 0)
			{
				ft_putchar(str[tab[0]]);
				tab[1]--;
			}
		}
		if (str[tab[0]] >= 'A' && str[tab[0]] <= 'Z')
		{
			tab[1] = str[tab[0]] - ('A' - 1);
			while (tab[1] != 0)
			{
				ft_putchar(str[tab[0]]);
				tab[1]--;
			}
		}
		tab[0]++;
	}
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	(void)argc;

	if (argv[1] == NULL)
		ft_putchar('\n');
	else
		repeat_alpha(argv[1]);
	return (0);
}
