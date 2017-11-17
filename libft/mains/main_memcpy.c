/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:23:31 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/10 15:59:53 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int		main(int ac, char **av)
{
	char	lol1[25] = "I Love Rock'n Roll !";
	char	lol1_2[25];
	char	lol2[25] = "I Love Rock'n Roll !";
	char	lol2_2[25];

	if (ac != 2)
	{
		printf("pas le bon nombre d'arguments\n");
		return (0);
	}
	ft_memcpy(lol1_2, lol1, atoi(av[1]));
	memcpy(lol2_2, lol2, atoi(av[1]));
	printf("%s  ----  %s\n%s  ----  %s\n", lol1, lol1_2, lol2, lol2_2);
	return (0);
}
