/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test17.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 10:51:25 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/17 09:11:53 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, int nb);

int		main(void)
{
	char tab_dest[50] = "Guillerot";
	char tab_src[] = " Lucas";
	printf("%s\n", ft_strncat(tab_dest, tab_src, 3));
	char tab_dest2[50] = "Guillerot";
	char tab_src2[] = " Lucas";
	printf("%s\n", strncat(tab_dest2, tab_src2, 3));
	return (0);
}
