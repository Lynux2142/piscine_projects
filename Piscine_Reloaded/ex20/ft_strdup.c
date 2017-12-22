/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:48:02 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/07 15:14:26 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*s1;

	i = 0;
	while (src[i])
		++i;
	s1 = (char *)malloc(sizeof(char) * (i + 1));
	if (s1 == NULL)
		exit(0);
	i = -1;
	while (src[++i])
		s1[i] = src[i];
	s1[i] = '\0';
	return (s1);
}
