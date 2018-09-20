/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_revalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 19:28:49 by exam              #+#    #+#             */
/*   Updated: 2017/07/07 19:39:50 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	maff_revalpha(void)
{
	int pair;
	int impair;

	pair = 1;
	impair = 0;
	while (impair < 26)
	{
		ft_putchar('z' - impair);
		impair += 2;
		ft_putchar('Z' - pair);
		pair += 2;
	}
	write(1, "\n", 1);
}

int		main(void)
{
	maff_revalpha();
	return (0);
}
