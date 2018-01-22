/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stock.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:52:41 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/22 17:21:15 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fdf.h"

void		ft_check_stock(int fd, t_shape *shape)
{
	char	*line;
	int		y;

	if (!(shape->max_h = (int *)ft_memalloc(sizeof(int))))
		return ;
	if (!(shape->min_h = (int *)ft_memalloc(sizeof(int))))
		return ;
	shape->current = ((t_slist *)shape->list);
	get_next_line(fd, &line);
	shape->previous = ft_add_first_line(shape, line, 0);
	ft_memdel((void *)&line);
	y = 1;
	while (get_next_line(fd, &line) > 0)
	{
		if (!(((t_slist *)shape->current)->next_y =
					(t_slist *)ft_memalloc(sizeof(t_slist))))
			return ;
		if (!(((t_slist *)shape->current)->next_y->link =
					(t_link *)ft_memalloc(sizeof(t_link))))
			return ;
		shape->current = ((t_slist *)shape->current)->next_y;
		shape->previous = ft_add_next_line(shape, line, y);
		ft_memdel((void *)&line);
		++y;
	}
	shape->max_l = y;
	ft_memdel((void *)&line);
}
