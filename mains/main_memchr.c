/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:23:02 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/10 15:59:06 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int		main(int ac, char **av)
{
	unsigned char	*mdr1;
	unsigned char	*mdr2;
	char			lol1[25] = "I Love Rock'n Roll !";
	char			lol2[25] = "I Love Rock'n Roll !";

	if (ac != 3)
	{
		printf("pas le bon nombre d'arguments\n");
		return (0);
	}
	mdr1 = ft_memchr(lol1, atoi(av[1]), atoi(av[2]));
	mdr2 = memchr(lol2, atoi(av[1]), atoi(av[2]));
	printf("%s\n", mdr1);
	printf("%s\n", mdr2);
	return (0);
}
