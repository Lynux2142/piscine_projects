/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 10:20:29 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/27 12:22:40 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list *elem;

	if (!(elem = malloc(sizeof(t_list))))
		return (0);
	elem->data = data;
	elem->next = NULL;
	return (elem);
}
