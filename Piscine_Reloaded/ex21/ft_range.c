/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:08:27 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/07 17:26:26 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *tab;
	int i;

	tab = NULL;
	if (min >= max)
		return (tab);
	tab = (int *)malloc(sizeof(int) * (max - min));
	if (tab == NULL)
		exit(0);
	i = 0;
	while ((min + i) < max)
	{
		tab[i] = (min + i);
		++i;
	}
	tab[i] = '\0';
	return (tab);
}
