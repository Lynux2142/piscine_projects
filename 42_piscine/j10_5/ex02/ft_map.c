/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 11:53:53 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/24 18:35:04 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *temp;

	if (!(temp = (int*)malloc(sizeof(int) * (length + 1))))
		return (0);
	i = 0;
	while (i < length)
	{
		temp[i] = f(tab[i]);
		++i;
	}
	return (temp);
}
