/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 10:22:55 by exam              #+#    #+#             */
/*   Updated: 2017/07/28 11:06:45 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_single_word(char *str)
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

int		ft_is_single(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			return (0);
		++i;
	}
	if (str [i] == '\0')
	{
		ft_print_single_word(str);
		return (1);
	}
	return (0);
}

void	ft_print_last_word(char *str)
{
	int i;

	if (ft_is_single(str) == 1)
		return ;
	i = 0;
	while (str[i])
		++i;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\0')
		--i;
	while (str[i - 1] != ' ' && str[i - 1] != '\t' && str[i - 1] != '\0')
		--i;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
	{
		ft_putchar(str[i]);
		++i;
	}
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	int i;
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
		++i;
	if (argv[1][i] == '\0')
	{
		write(1, "\n", 1);
		return (0);
	}
	ft_print_last_word(argv[1]);
	return (0);
}
