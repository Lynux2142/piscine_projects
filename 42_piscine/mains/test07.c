/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test06.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 18:49:14 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/12 19:28:52 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int		ft_strncmp(char *s1, char *s2, unsigned int n);

int		main(void)
{
	printf("%d\n", ft_strncmp("a1b2g5", "a1b2gl", 5));
	printf("%d\n", strncmp("a1b2g5", "a1b2gl", 5));
	return (0);
}
