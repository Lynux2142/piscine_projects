/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 19:42:26 by exam              #+#    #+#             */
/*   Updated: 2017/07/07 20:36:50 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	ft_putchar(*str);
}

int		main(void)
{
	char *str;
	char car_chain;

	car_chain = *"I love 42!";
	str = &car_chain;
	ft_putchar(*str);
	return (0);
}
