/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 11:16:07 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/16 16:38:35 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int		main(void)
{
	char temp[100];

	ft_strncpy(temp, "I love Rock'N \nRoll !", 20);
	printf("%s\n", temp);
	strncpy(temp, "I love Rock'N \nRoll !", 20);
	printf("%s\n", temp);
	return (0);
}
