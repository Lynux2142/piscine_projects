/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test06.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 18:49:14 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/16 16:40:48 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int		ft_strcmp(char *s1, char *s2);

int		main(void)
{
	printf("%d\n", ft_strcmp("a1b2g5", "a1b2g9"));
	printf("%d\n", strcmp("a1b2g5", "a1b2g9"));
	return (0);
}
