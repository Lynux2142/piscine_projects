/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 20:56:24 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/18 17:17:33 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int i;
	int *tab;

	tab = NULL;
	if (min >= max)
		return (tab);
	tab = (int*)malloc(sizeof(int) * ((max - min) + 1));
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
