/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:09:22 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/10 09:32:37 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int		main(void)
{
	char temp1[10];
	char temp2[10];

	ft_strcpy(temp1, "AAAAAAAAB");
	printf("%s\n", temp1);
	strcpy(temp2, "AAAAAAAAB");
	printf("%s\n", temp2);
	return (0);
}
