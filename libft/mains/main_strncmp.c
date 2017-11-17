/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strncmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:41:07 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/10 16:01:29 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int		main(int ac, char **av)
{
	if (ac != 4)
	{
		printf("pas le bon nombre d'arguments !\n");
		return (1);
	}
	printf("%d\n", ft_strncmp(av[1], av[2], atoi(av[3])));
	printf("%d\n", strncmp(av[1], av[2], atoi(av[3])));
	return (0);
}
