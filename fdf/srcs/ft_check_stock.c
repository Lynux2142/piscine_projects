/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stock.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:52:41 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/23 17:48:47 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fdf.h"

void		ft_check_stock(int fd, t_shape *shape)
{
	char	*line;
	int		y;

	if (!(shape->max_y = (int *)ft_memalloc(sizeof(int)))
	|| !(shape->max_x = (int *)ft_memalloc(sizeof(int)))
	|| !(shape->min_y = (int *)ft_memalloc(sizeof(int)))
	|| !(shape->min_x = (int *)ft_memalloc(sizeof(int))))
		return ;
	shape->current = ((t_slist *)shape->list);
	get_next_line(fd, &line);
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
