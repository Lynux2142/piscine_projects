/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test16.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 09:23:03 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/17 09:12:57 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src);

int		main(void)
{
	char tab_dest[50] = "Guillerot";
	char tab_src[] = " Lucas";
	printf("%s\n", ft_strcat(tab_dest, tab_src));
	char tab_dest2[50] = "Guillerot";
	char tab_src2[] = " Lucas";
	printf("%s\n", strcat(tab_dest2, tab_src2));
	return (0);
}
