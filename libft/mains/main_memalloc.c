/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memalloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:47:56 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/17 13:33:44 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	size_t	size = 514;
	char	*cmp = malloc(size);
	int		diff;
	char	*ret = ft_memalloc(size);
	bzero(cmp, size);
	if ((diff = memcmp(cmp, ret, size)))
		ft_putstr("0\n");
	else
		ft_putstr("1\n");
	free(ret);
	return (0);
}
