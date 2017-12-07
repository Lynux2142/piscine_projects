/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:26:36 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/07 11:33:03 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>

void	ft_print(char c)
{
	write(1, &c, 1);
}

void	ft_putchar(int c)
{
	if (c >= 16777215)
	{
		ft_print((char)(c >> 24));
		ft_print((char)(c >> 16));
		ft_print((char)(c >> 8));
		ft_print((char)c);
	}
	else if (c >= 65535)
	{
		ft_print((char)(c >> 16));
		ft_print((char)(c >> 8));
		ft_print((char)c);
	}
	else if (c >= 255)
	{
		ft_print((char)(c >> 8));
		ft_print((char)c);
	}
	else
		ft_print((char)c);
}
