/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 11:15:39 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/16 16:30:55 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char *dest, char *src);

int		main(void)
{
	char temp[10];

	ft_strcpy(temp, "UTgyEmEwSdwskiWVdaslVBAOitdeYLxmEdMjevnj");
	printf("%s\n", temp);
	strcpy(temp, "UTgyEmEwSdwskiWVdaslVBAOitdeYLxmEdMjevnj");
	printf("%s\n", temp);
	return (0);
}
