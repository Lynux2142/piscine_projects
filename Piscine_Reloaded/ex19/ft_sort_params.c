/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:19:30 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/07 17:50:22 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] || s1[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		++i;
	}
	return (0);
}

int		ft_print_params(char **av)
{
	int i;
	int j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			ft_putchar(av[i][j]);
			++j;
		}
		ft_putchar('\n');
		++i;
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		i;
	int		j;

	if (ac == 1)
		return (0);
	i = 1;
	while (av[i + 1])
	{
		j = 1;
		while (av[j + 1])
		{
			if (ft_strcmp(av[j], av[j + 1]) > 0)
			{
				av[0] = av[j];
				av[j] = av[j + 1];
				av[j + 1] = av[0];
			}
			++j;
		}
		++i;
	}
	ft_print_params(av);
	return (0);
}
