/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memccpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:22:52 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/16 15:21:00 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

#define RANDT 512
#define LONG 10000
#define D_ERROR	{ printf("Error Line %d, Funct %s\n", __LINE__ - 1, __func__); return (0);}

int		main(void)
{
	char			ctab[11], ctab2[11], ctab3[11];
	int				itab[11], itab2[11], itab3[11];
	unsigned long	ltab[11], ltab2[11], ltab3[11];
	int				i, j;
	size_t			k;
	void			*temp, *temp2;

	memccpy(NULL, NULL, 0, 0);
	ft_memccpy(NULL, NULL, 0, 0);
	k = 0;
	while (k <= sizeof(ltab))
	{
		i = 0;
		while (i < RANDT)
		{
			j = 0;
			while (j < 11)
			{
				ctab[j] = (char)rand();
				ctab2[j] = 0; ctab3[j] = 0;
				itab[j] = rand();
				itab2[j] = 0; itab3[j] = 0;
				ltab[j] = (unsigned long)rand() * LONG;
				ltab2[j] = 0; ltab3[j] = 0;
				j++;
			}
			temp = memccpy(ctab2, ctab, 'a', (k < sizeof(ctab)) ? k : sizeof(ctab));
			memcpy(ctab3, ctab2, sizeof(ctab));
			memset(ctab2, 0, sizeof(ctab2));
			temp2 = ft_memccpy(ctab2, ctab, 'a', (k < sizeof(ctab)) ? k : sizeof(ctab));
			if ((memcmp(ctab2, ctab3, sizeof(ctab)) != 0 || (temp != temp2)))
				D_ERROR
					temp = memccpy(itab2, itab, 'a', (k < sizeof(itab)) ? k : sizeof(itab));
			memcpy(itab3, itab2, sizeof(itab));
			memset(itab2, 0, sizeof(itab2));
			temp2 = ft_memccpy(itab2, itab, 'a', (k < sizeof(itab)) ? k : sizeof(itab));
			if ((memcmp(itab2, itab3, sizeof(itab)) != 0 || (temp != temp2)))
				D_ERROR
					temp = memccpy(ltab2, ltab, 'a', (k < sizeof(ltab)) ? k : sizeof(ltab));
			memcpy(ltab3, ltab2, sizeof(ltab));
			memset(ltab2, 0, sizeof(ltab2));
			temp2 = ft_memccpy(ltab2, ltab, 'a', (k < sizeof(ltab)) ? k : sizeof(ltab));
			if ((memcmp(ltab2, ltab3, sizeof(ltab)) != 0 || (temp != temp2)))
				D_ERROR
			++i;
		}
		++k;
	}
	return (1);
}
