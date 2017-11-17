/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strncpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:18:09 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/10 17:09:11 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int		main(int ac, char **av)
{
	char	*src = "stars";
	char	temp1[50];
	char	temp2[50];

	if (ac != 2)
	{
		printf("pas le bon nombre d'arguments !\n");
		return (1);
	}
	ft_strncpy(temp1, src, atoi(av[1]));
	ft_putstr(temp1);
	ft_putchar('\n');
	strncpy(temp2, src, atoi(av[1]));
	ft_putstr(temp2);
	ft_putchar('\n');
	return (0);
}
