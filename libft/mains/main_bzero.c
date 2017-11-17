/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:22:42 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/10 15:58:18 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int		main(int ac, char **av)
{
	char	lol1[25] = "I Love Rock'n Roll !";
	char	lol2[25] = "I Love Rock'n Roll !";

	if (ac != 2)
	{
		printf("pas le bon nombre d'arguments\n");
		return (0);
	}
	ft_bzero(lol1, atoi(av[1]));
	bzero(lol2, atoi(av[1]));
	printf("%s\n%s\n", lol1, lol2);
	return (0);
}
