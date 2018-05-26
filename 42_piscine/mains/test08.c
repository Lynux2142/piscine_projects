/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test08.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 15:07:58 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/13 10:56:41 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str);

int		main(void)
{
	char tab[] = "I Love Rock'N Roll !";
	printf("%s", ft_strupcase(tab));
	return (0);
}
