/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 20:20:51 by exam              #+#    #+#             */
/*   Updated: 2017/07/14 20:34:18 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		max(int *tab, unsigned int len)
{
	int i;
	int j;
	int temp;

	j = 0;
	i = len;
	if (tab == NULL)
		return (0);
	while (i != 0)
	{
		j = 0;
		while (j != len)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j +1];
				tab[j + 1] = temp;
			}
			j++; 
		}
		i--;
	}
	return (tab[j - 1]);
}
