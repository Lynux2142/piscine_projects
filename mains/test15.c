/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test15.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 09:07:18 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/13 09:19:31 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_str_is_printable(char *str);

int		main(void)
{
	char tab[] = "fdl;gk;lfk";
	printf("%d", ft_str_is_printable(tab));
	return (0);
}
