/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:22:02 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/10 15:59:29 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int		main(int ac, char **av)
{
	char	lol1[25] = "I Love R";
	char	lol2[25] = "I Love Rock'n Roll !";

	if (ac != 2)
	{
		printf("pas le bon nombre d'arguments\n");
		return (0);
	}
	printf("%d\n", ft_memcmp(lol1, lol2, atoi(av[1])));
	printf("%d\n", memcmp(lol1, lol2, atoi(av[1])));
	return (0);
}
