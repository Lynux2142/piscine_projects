/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memmove_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 09:56:06 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/13 09:59:38 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int		main(void)
{
	char	*src = "Bonjour jean claude guss kevin albert";
	char	dst1[10];
	char	dst2[10];

	ft_memmove(dst1, src, 9);
	memmove(dst2, src, 9);
	printf("%s  ----  %s\n%s  ----  %s\n", src, dst1, src, dst2);
	return (0);
}
