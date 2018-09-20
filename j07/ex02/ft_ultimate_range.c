/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 09:42:20 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/18 17:37:34 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int *tab;
	int i;

	tab = NULL;
	if (min >= max)
		return (0);
	tab = (int*)malloc(sizeof(int) * ((max - min) + 1));
	if (tab == NULL)
		exit(0);
	i = 0;
	while ((min + i) < max)
	{
		tab[i] = (min + i);
		++i;
	}
	*range = tab;
	return (max - min);
}
