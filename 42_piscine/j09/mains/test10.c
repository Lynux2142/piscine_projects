/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test10.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 09:44:03 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/14 13:54:03 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_scrambler(int ***a, int *b, int *******c, int ****d);

int		main(void)
{
	int a3;
	int *a2;
	int **a1;
	int ***a;
	int b2;
	int *b;
	int c7;
	int *c6;
	int **c5;
	int ***c4;
	int ****c3;
	int *****c2;
	int ******c1;
	int *******c;
	int d4;
	int *d3;
	int **d2;
	int ***d1;
	int ****d;

	a3 = 1;
	a2 = &a3;
	a1 = &a2;
	a = &a1;
	b2 = 2;
	b = &b2;
	c7 = 3;
	c6 = &c7;
	c5 = &c6;
	c4 = &c5;
	c3 = &c4;
	c2 = &c3;
	c1 = &c2;
	c = &c1;
	d4 = 4;
	d3 = &d4;
	d2 = &d3;
	d1 = &d2;
	d = &d1;
	ft_scrambler(a,b,c,d);
	printf("%d, %d, %d, %d", ***a, *b, *******c, ****d);
	return (0);
}
