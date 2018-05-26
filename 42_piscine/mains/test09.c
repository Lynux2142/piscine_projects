/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test09.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 20:04:48 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/13 10:56:52 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str);

int		main(void)
{
	char tab[] = "I Love Rock'N Roll !";
	printf("%s", ft_strlowcase(tab));
	return (0);
}
