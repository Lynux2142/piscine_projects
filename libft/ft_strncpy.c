/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:42:04 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/09 11:52:42 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = -1;
	while (++i < len && *(src + i))
		*(dst + i) = *(src + i);
	--i;
	while (++i < len)
		*(dst + i) = '\0';
	return (dst);
}
