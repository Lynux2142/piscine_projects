/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:44:39 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/17 13:36:26 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	char	lol1[25] = "I Love Rock'n Roll !";
	char	lol2[25] = "I Love Rock'n Roll !";

	if (ac != 3)
	{
		printf("pas le bon nombre d'arguments\n");
		return (0);
	}
	ft_memset(lol1, atoi(av[1]), atoi(av[2]));
	memset(lol2, atoi(av[1]), atoi(av[2]));
	printf("%s\n%s\n", lol1, lol2);
	return (0);
}
