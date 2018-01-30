/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 10:04:09 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/30 14:44:27 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_draw_funct(t_shape *shape)
{
	t_slist		*i;
	t_slist		*j;
	int			color;

	i = shape->list;
	while (i)
	{
		j = i;
		while (j)
		{
			if (j->next_y)
				color = ft_calcul_color(j, j->next_y);
			if (j->next_y)
				ft_draw_segment(shape, (t_link *)j->link,
						(t_link *)j->next_y->link, color);
			if (j->next_x)
				color = ft_calcul_color(j, j->next_x);
			if (j->next_x)
				ft_draw_segment(shape, (t_link *)j->link,
						(t_link *)j->next_x->link, color);
			j = j->next_x;
		}
		i = i->next_y;
	}
}

static void		ft_xtrem_values(t_shape *shape, t_link *ptr)
{
	if (!shape->max_y || *shape->max_y < ptr->v)
		*shape->max_y = ptr->v;
	if (!shape->max_x || *shape->max_x < ptr->u)
		*shape->max_x = ptr->u;
	if (!shape->min_y || *shape->min_y > ptr->v)
		*shape->min_y = ptr->v;
	if (!shape->min_x || *shape->min_x > ptr->u)
		*shape->min_x = ptr->u;
}

void			ft_projection(t_shape *shape)
{
	t_slist		*i;
	t_slist		*j;
	t_link		*ptr;

	i = shape->list;
	while (i)
	{
		j = i;
		while (j)
		{
			ptr = (t_link *)j->link;
			projection_calcul_u(shape, ptr);
			projection_calcul_v(shape, ptr);
			if (shape->first == 0)
				ft_xtrem_values(shape, ptr);
			j = j->next_x;
		}
		i = i->next_y;
	}
	shape->first = 1;
	ft_draw_funct(shape);
}

void			ft_draw(t_shape *shape)
{
	shape->mlx = mlx_init();
	shape->win_x = 1200;
	shape->win_y = 1200;
	shape->img_x = shape->win_x;
	shape->img_y = shape->win_y;
	shape->agr = 1;
	shape->win = mlx_new_window(shape->mlx, shape->win_x, shape->win_y, "test");
	shape->img = mlx_new_image(shape->mlx, shape->img_x, shape->img_y);
	shape->data = mlx_get_data_addr(shape->img, &shape->bpp,
			&shape->sizeline, &shape->endian);
	shape->start_x = (*shape->min_x - 100);
	shape->start_y = (shape->img_y / 2 - *shape->max_y);
	shape->coef_x = 31;
	shape->coef_y = 13;
	shape->coef_z = 33;
	shape->coef_a = 0;
	ft_projection(shape);
	mlx_put_image_to_window(shape->mlx, shape->win, shape->img, 0, 0);
	mlx_key_hook(shape->win, ft_key_funct, shape);
	mlx_mouse_hook(shape->win, ft_mouse_funct, shape);
	mlx_loop(shape->mlx);
}
