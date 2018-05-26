/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test19.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 11:04:21 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/16 16:47:25 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int		main(void)
{
	char tab_dest[50] = "Guillerot";
	char tab_src[] = "Lucas";
	char tab_dest2[50] = "Guillerot";
	char tab_src2[] = "Lucas";
	printf("%u\n", ft_strlcpy(tab_dest, tab_src, 12));
	printf("%s\n", tab_dest);
	printf("%s\n", tab_src);
	printf("%u\n", ft_strlcpy(tab_dest, tab_src, 2));
	printf("%s\n", tab_dest);
	printf("%s\n", tab_src);
	printf("--------------------\n");
	printf("%lu\n", strlcpy(tab_dest2, tab_src2, 12));
	printf("%s\n", tab_dest2);
	printf("%s\n", tab_src2);
	printf("%lu\n", strlcpy(tab_dest2, tab_src2, 2));
	printf("%s\n", tab_dest2);
	printf("%s\n", tab_src2);
	return (0);
}
