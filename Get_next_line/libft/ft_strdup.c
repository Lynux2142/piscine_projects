/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:54:13 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/14 11:10:13 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dst;

	i = 0;
	while (s1[i])
		++i;
	if (!(dst = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = -1;
	while (s1[++i])
		dst[i] = s1[i];
	dst[i] = '\0';
	return (dst);
}
