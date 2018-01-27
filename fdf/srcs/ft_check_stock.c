/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stock.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:52:41 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/27 12:02:22 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_check_stock(int fd, t_shape *shape)
{
	char	*line;
	int		y;

	shape->current = ((t_slist *)shape->list);
	if (get_next_line(fd, &line) <= 0)
	{
		ft_putendl("error: Not valid file. Exiting.");
		exit(-1);
	}
	shape->previous = ft_add_first_line(shape, line, 0);
	ft_memdel((void *)&line);
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!(((t_slist *)shape->current)->next_y =
		(t_slist *)ft_memalloc(sizeof(t_slist)))
		|| !(((t_slist *)shape->current)->next_y->link =
		(t_link *)ft_memalloc(sizeof(t_link))))
			return ;
		shape->current = ((t_slist *)shape->current)->next_y;
		shape->previous = ft_add_next_line(shape, line, ++y);
		ft_memdel((void *)&line);
	}
	ft_memdel((void *)&line);
}
