/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test14.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 09:03:47 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/13 09:07:08 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_str_is_uppercase(char *str);

int		main(void)
{
	char tab[] = "fdfdlsf";
	printf("%d", ft_str_is_uppercase(tab));
	return (0);
}
