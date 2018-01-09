/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 13:29:00 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/09 12:36:22 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrealloc(void *str, size_t size)
{
	void	*tmp;

	if (size == 0 && str)
	{
		ft_memdel(&str);
		if (!(tmp = ft_memalloc(1)))
			return (NULL);
		return (tmp);
	}
	else if (size > 0)
	{
		tmp = str;
		if (!(str = ft_memalloc(size)))
			return (NULL);
		if (tmp)
		{
			ft_memcpy(str, tmp, size);
			ft_memdel(&tmp);
		}
	}
	return (str);
}
