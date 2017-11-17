/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memccpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 10:41:47 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/16 10:48:21 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		main(void)
{
	char	*src = "test basic du memccpy !";
	char	buff1[22];
	char	buff2[22];

	ft_memccpy(buff1, src, 'm', 6);
	memccpy(buff2, src, 'm', 6);
	printf("%c\n%s\n", buff1[7], buff1);
	printf("%c\n%s\n", buff2[7], buff2);
	return (0);
}
