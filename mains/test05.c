/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test05.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 12:51:45 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/15 21:43:16 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find);

int		main(void)
{
	printf("%s\n", ft_strstr("jean cla claude guss", "claude "));
	printf("%s\n", ft_strstr("jean claude guss", "lol"));
	printf("%s\n", ft_strstr("jean claude guss", "cl"));
	printf("------------------\n");
	printf("%s\n", strstr("jean cla claude guss", "claude "));
	printf("%s\n", strstr("jean claude guss", "lol"));
	printf("%s\n", strstr("jean claude guss", "cl"));
	return (0);
}
