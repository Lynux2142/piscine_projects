/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 21:15:25 by exam              #+#    #+#             */
/*   Updated: 2017/07/21 21:39:35 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_minimalize(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		++i;
	}
	return (str);
}

char	*ft_capitalizer(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
		&& (str[i - 1] < '0' || (str[i - 1] > '9' && str[i - 1] < 'A')
		|| (str[i - 1] > 'Z' && str[i - 1] < 'a') || str[i - 1] > 'z'))
			str[i] -= 32;
		++i;
	}
	return (str);
}

int		main(int argc, char **argv)
{
	int i;
	int j;

	(void)argc;
	i = 1;
	while (argv[i] != 0)
	{
		ft_minimalize(argv[i]);
		ft_capitalizer(argv[i]);
		j = 0;
		while (argv[i][j] != '\0')
		{
			ft_putchar(argv[i][j]);
			++j;
		}
		ft_putchar('\n');
		++i;
	}
	return (0);
}
