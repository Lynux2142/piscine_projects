/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 15:34:51 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/20 15:41:09 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*lst_add_end(t_list *lst, void *s, size_t len)
{
	t_list *elem;
	t_list		 *curs;

	if (!(elem = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	elem->content = s;
	elem->content_size = len;
	elem->next = NULL;
	if (!lst)
		return (elem);
	else
	{
		curs = lst;
		while (curs->next)
			curs = curs->next;
		curs->next = elem;
		return (lst);
	}
}
