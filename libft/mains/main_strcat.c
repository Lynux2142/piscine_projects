/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:28:36 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/09 15:33:30 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int		main(void)
{
	char tab_dest[50] = "Guillerot";
	char tab_src[] = " Lucas";
	char tab_dest2[50] = "Guillerot";
	char tab_src2[] = " Lucas";

	printf("%s\n", ft_strcat(tab_dest, tab_src));
	printf("%s\n", strcat(tab_dest2, tab_src2));
	return (0);
}
