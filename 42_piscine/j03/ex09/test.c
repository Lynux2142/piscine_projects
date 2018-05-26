/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 08:40:12 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/11 21:33:20 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_integer_table(int *tab, int size);

int		main(void)
{
	int tab[6];

	tab[0] = 42;
	tab[1] = 12;
	tab[2] = 2;
	tab[3] = 23;
	tab[4] = 18;
	tab[5] = 1;
	ft_sort_integer_table(tab, 6);
	printf("%d", tab[5]);
	return (0);
}
