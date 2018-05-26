/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 19:59:20 by exam              #+#    #+#             */
/*   Updated: 2017/07/21 20:18:18 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int i;

	if (argc == 1 || argc > 2)
	{
		ft_putchar('\n');
		return (0);
	}
	i = 0;
	while (argv[1][i] != '\0')
		++i;
	while (argv[1][i] == ' ' || argv[1][i] == '\t' || argv[1][i] == '\0')
		--i;
	while (argv[1][i] != ' ' && argv[1][i] != '\t')
		--i;
	++i;
	while (argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '\0')
	{
		ft_putchar(argv[1][i]);
		++i;
	}
	ft_putchar('\n');
	return (0);
}
