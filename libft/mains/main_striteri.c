/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_striteri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:37:12 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/15 15:57:12 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lol(unsigned int i, char *s)
{
	*s = *s + i;
}

int		main(void)
{
	char	*str = "Hello";

	ft_striteri(NULL, NULL);
	ft_striteri(str,NULL);
	ft_striteri(str, ft_lol);
	return (0);
}
