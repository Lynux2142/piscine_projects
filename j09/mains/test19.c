/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test19.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 10:48:37 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/14 16:48:05 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_unmatch(int *tab, int length);

int		main(void)
{
	int tab[7] = {1, 1, 3, 2, 4, 3, 4};
	printf("%d\n", ft_unmatch(tab, 7));
	printf("%d\n", tab[0]);
	printf("%d\n", tab[1]);
	printf("%d\n", tab[2]);
	printf("%d\n", tab[3]);
	printf("%d\n", tab[4]);
	printf("%d\n", tab[5]);
	printf("%d\n", tab[6]);
	return (0);
}
