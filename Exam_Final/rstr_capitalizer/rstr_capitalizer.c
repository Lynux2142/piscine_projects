/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 11:10:18 by exam              #+#    #+#             */
/*   Updated: 2017/07/28 11:29:28 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		++i;
	}
	write(1, "\n", 1);
}

char	*ft_lowcase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		++i;
	}
	return (str);
}

void	ft_capitalize(char *str)
{
	int i;

	ft_lowcase(str);
	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z')
		&& (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0'))
			str[i] -= 32;
		++i;
	}
	ft_putstr(str);
}

int 	main(int argc, char **argv)
{
	int i;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		ft_capitalize(argv[i]);
		++i;
	}
	return (0);
}
