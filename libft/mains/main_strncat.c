/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strncat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:34:47 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/10 16:00:49 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int		main(int ac, char **av)
{
	char tab_dest[50] = "Guillerot";
	char tab_src[] = " Lucas";
	char tab_dest2[50] = "Guillerot";
	char tab_src2[] = " Lucas";

	if (ac != 2)
	{
		printf("pas le bonnombre d'argments !\n");
		return (1);
	}
	printf("%s\n", ft_strncat(tab_dest, tab_src, (int)strtol(av[1], NULL, 10)));
	printf("%s\n", strncat(tab_dest2, tab_src2, (int)strtol(av[1], NULL, 10)));
	return (0);
}
