/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 10:40:15 by lguiller          #+#    #+#             */
/*   Updated: 2018/03/19 17:09:51 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		put_rect(t_shape *shape, t_rect *rect)
{
	int x;
	int y;

	x = rect->pos_x;
	while (x <= (rect->pos_x + rect->dim_x))
	{
		y = rect->pos_y;
		while (y <= (rect->pos_y + rect->dim_y))
		{
			fill_pixel(shape, x, y, rect->col);
			++y;
		}
		++x;
	}
}

static void	ft_mand_string(t_shape *shape, t_rect *rect)
{
	rect->pos_y = 10;
	put_rect(shape, rect);
	mlx_put_image_to_window(shape->mlx, shape->win, shape->img, 0, 0);
}

static void	ft_julia_string(t_shape *shape, t_rect *rect)
{
	rect->pos_y = 50;
	put_rect(shape, rect);
	mlx_put_image_to_window(shape->mlx, shape->win, shape->img, 0, 0);
}

static void	ft_burn_string(t_shape *shape, t_rect *rect)
{
	rect->pos_y = 90;
	put_rect(shape, rect);
	mlx_put_image_to_window(shape->mlx, shape->win, shape->img, 0, 0);
}

void		ft_set_string(t_shape *shape)
{
	t_rect	rect;

	rect.pos_x = 5;
	rect.dim_x = 120;
	rect.dim_y = 25;
	rect.col = RED;
	if (shape->string.mand == 0)
		ft_mand_string(shape, &rect);
	if (shape->string.julia == 0)
		ft_julia_string(shape, &rect);
	if (shape->string.burn == 0)
		ft_burn_string(shape, &rect);
	mlx_string_put(shape->mlx, shape->win, 10, 10,
			shape->string.mand, "Mandelbrot");
	mlx_string_put(shape->mlx, shape->win, 10, 50,
			shape->string.julia, "Julia");
	mlx_string_put(shape->mlx, shape->win, 10, 90,
			shape->string.burn, "BurningShip");
}
