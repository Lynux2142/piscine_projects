/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 11:18:20 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/20 13:30:27 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

char		*ft_realloc(void *s1, int len)
{
	char	*s2;
	int		len_s1;

	if (s1)
	{
		len_s1 = ft_strlen((char *)s1);
		if (!(s2 = ft_memalloc((len_s1 + len))))
			return (NULL);
		s2 = (char *)ft_memcpy(s2, s1, len_s1);
	}
	else
	{
		if (!(s2 = ft_memalloc(len)))
			return (NULL);
	}
	return ((char *)s2);
}
