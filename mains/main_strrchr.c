/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:24:52 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/10 15:52:16 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int		main(int ac, char **av)
{
	char	lol1[20] = "I Love Rock'n Roll !";
	char	lol2[20] = "I Love Rock'n Roll !";
	char	*mdr1;
	char	*mdr2;

	if (ac != 2)
	{
		printf("pas le bon nombre d'arguments !\n");
		return (1);
	}
	mdr1 = ft_strrchr(lol1, atoi(av[1]));
	printf("%s\n", mdr1);
	mdr2 = strrchr(lol2, atoi(av[1]));
	printf("%s\n", mdr2);
	return (0);
}
