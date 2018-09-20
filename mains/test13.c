/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 08:54:33 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/16 09:46:50 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_str_is_lowercase(char *str);

int		main(void)
{
	char tab[] = "aaa";
	printf("%d", ft_str_is_lowercase(tab));
	return (0);
}
