/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lstdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:17:25 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/16 18:29:05 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	uf_del_callback(void *d, size_t s)
{
	free(d);
	(void)s;
}

int		main(void)
{
	t_list	*begin;
	size_t	v;

	v = 1;
	begin = ft_lstnew(&v, sizeof(void *));
	begin->next = ft_lstnew(&v, sizeof(void *));
	begin->next->next = ft_lstnew(&v, sizeof(void *));
	ft_lstdel(&begin, uf_del_callback);
	if (begin != NULL)
	{
		ft_putstr("NOPE");
		return (1);
	}
	ft_putstr("OK");
	return (0);
}
