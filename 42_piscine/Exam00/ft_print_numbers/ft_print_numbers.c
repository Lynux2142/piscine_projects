/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 18:58:00 by exam              #+#    #+#             */
/*   Updated: 2017/07/07 20:01:32 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void 	ft_putchar(char c)
{
	write(1, &c, 1);
}

void 	ft_print_numbers(void)
{
	int i;

	i = 0;
	while (i < 10)
	{
		ft_putchar('0' + i);
		i++;
	}
}

int		main(void)
{
	ft_print_numbers();
	return (0);
}
