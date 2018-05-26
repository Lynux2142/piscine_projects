/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/07 20:39:47 by exam              #+#    #+#             */
/*   Updated: 2017/07/07 21:04:03 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 2);
}

void	ft_swap(int *a, int *b)
{
	*a = *b;
	*b = *a;
	ft_putchar('0' + *a);
	ft_putchar('0' + *b);
}

int		main(void)
{
	int nb1;
	int nb2;
	int *a;
	int *b;
	
	nb1 = 3;
	nb2 = 7;
	a = &nb1;
	b = &nb2;
	ft_swap(a, b);
	return (0);
}
