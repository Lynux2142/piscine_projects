/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lstadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:23:56 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/14 15:37:04 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(void)
{
	t_list *l = ft_lstnew(strdup("nyacat"), 8);
	t_list *n = ft_lstnew(strdup("OK"), 3);

	ft_lstadd(&l, n);
	if (l == n && !strcmp(l->content, "OK") && l->content_size == 3)
	{
		ft_putstr("Ok");
		return (0);
	}
	ft_putstr("Pas Ok");
	return (0);
}
