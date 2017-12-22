/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:29:00 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/22 14:16:14 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrealloc(void *str, size_t size)
{
	void	*tmp;
	int		i;

	tmp = str;
	if (!(str = ft_strnew(size)))
		return (NULL);
	i = -1;
	while (*(char *)&tmp[++i])
		*(char *)&str[i] = *(char *)&tmp[i];
	ft_memdel(&tmp);
	return (str);
}
