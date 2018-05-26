/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 20:54:06 by exam              #+#    #+#             */
/*   Updated: 2017/07/21 21:13:14 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_abs(int start, int end)
{
	int result;

	if (start < 0)
		start *= - 1;
	if (end < 0)
		end *= -1;
	result = (end - start);
	return (result);
}

int		*ft_range(int start, int end)
{
	int *tab;
	int len;
	int i;

	len = ft_abs(start, end);
	if (!(tab = (int*)malloc(sizeof(int) * (len + 1))))
		return (0);
	i = 0;
	while (start <= end)
	{
		tab[i] = start;
		start++;
		++i;
	}
	tab[i] = '\0';
	return (tab);
}
