/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test18.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 15:24:48 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/17 09:37:13 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int		main(void)
{
	char tab_dest[50] = "Guill";
	char tab_src[] = "Lucas";
	char tab_dest2[50] = "Guill";
	char tab_src2[] = "Lucas";
	printf("%u\n", ft_strlcat(tab_dest, tab_src, 5));
	printf("%s\n", tab_dest);
	printf("%s\n", tab_src);
	printf("--------------------\n");
	printf("%lu\n", strlcat(tab_dest2, tab_src2, 5));
	printf("%s\n", tab_dest2);
	printf("%s\n", tab_src2);
	return (0);
}
