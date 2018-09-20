/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdown.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 19:06:07 by exam              #+#    #+#             */
/*   Updated: 2017/07/07 20:01:47 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_countdown(void)
{
	int i;

	i = 0;
	while (i < 10)
	{
		ft_putchar('9' - i);
		i++;
	}
	write(1, "\n", 1);
}

int		main(void)
{
	ft_countdown();
	return (0);
}
