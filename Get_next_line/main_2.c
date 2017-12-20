/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 11:18:56 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/20 12:28:16 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>

char		*ft_realloc(void *s1, int len);

int			main(void)
{
	char *bonjour;

	bonjour = "salut ";
	bonjour = ft_realloc(bonjour, sizeof(char) * 3);
	bonjour[6] = 'j';
	bonjour[7] = 'e';
	bonjour[8] = ' ';
	bonjour = ft_realloc(bonjour, sizeof(char) * 8);
	bonjour[9] = 'm';
	bonjour[10] = '\'';
	bonjour[11] = 'a';
	bonjour[12] = 'p';
	bonjour[13] = 'p';
	bonjour[14] = 'e';
	bonjour[15] = 'l';
	bonjour[16] = ' ';
	bonjour = ft_realloc(bonjour, sizeof(char) * 6);
	bonjour[17] = 'L';
	bonjour[18] = 'u';
	bonjour[19] = 'c';
	bonjour[20] = 'a';
	bonjour[21] = 's';
	bonjour[22] = '\0';
	printf("%s\n", bonjour);
	return (0);
}
