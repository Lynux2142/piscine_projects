/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_funct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 12:30:34 by lguiller          #+#    #+#             */
/*   Updated: 2018/03/16 14:19:59 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_move_fract(int key, t_shape *shape)
{
	if (key == 126)
	{
		shape->y1 -= (10.0 / shape->zoom);
		shape->y2 -= (10.0 / shape->zoom);
	}
	if (key == 123)
	{
		shape->x1 -= (10.0 / shape->zoom);
		shape->x2 -= (10.0 / shape->zoom);
	}
	if (key == 125)
	{
		shape->y1 += (10.0 / shape->zoom);
		shape->y2 += (10.0 / shape->zoom);
	}
	if (key == 124)
	{
		shape->x1 += (10.0 / shape->zoom);
		shape->x2 += (10.0 / shape->zoom);
	}
}

int			ft_key_funct(int key, t_shape *shape)
{
	if (key == 123 || key == 124 || key == 125 || key == 126)
		ft_move_fract(key, shape);
	if (key == 24)
		shape->iter += 10.0;
	if (key == 27)
		shape->iter -= 10.0;
	if (key == 49)
		ft_reset_fract(shape);
	if (key == 36)
		shape->color =
			(shape->color < 1 || shape->color > 6) ? 1 : ++shape->color;
	if (key == 258)
		shape->ok = (shape->ok == 1) ? 0 : 1;
	if (key == 53)
		exit(0);
	ft_display(shape);
	if (key == 3)
	{
		ft_create_fdf(shape, shape->data);
		mlx_string_put(shape->mlx, shape->win, 340, 289, 0xFF0000,
				"File Created");
	}
	ft_set_string(shape);
	return (0);
}
