/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 12:53:32 by lguiller          #+#    #+#             */
/*   Updated: 2018/02/20 11:08:59 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static void	ft_reset_fract(t_shape *shape)
{
	shape->zoom = 500.0;
	if (ft_strequ("fract1", shape->fract_name) == 1)
	{
		shape->iter = 50.0;
		shape->x1 = -2.2;
		shape->x2 = 2.2;
		shape->y1 = -1.2;
		shape->y2 = 1.2;
	}
	else if (ft_strequ("fract2", shape->fract_name) == 1)
	{
		shape->iter = 150.0;
		shape->x1 = -1.6;
		shape->x2 = 1.6;
		shape->y1 = -1.2;
		shape->y2 = 1.2;
	}
	else if (ft_strequ("fract3", shape->fract_name) == 1)
	{
		shape->iter = 50.0;
		shape->x1 = -2.0;
		shape->x2 = 2.0;
		shape->y1 = -1.8;
		shape->y2 = 1.8;
	}
}

int			ft_var_julia(int x, int y, t_shape *shape)
{
	double	mouse_re;
	double	mouse_im;

	ft_clear(shape);
	mouse_re = (double)x / (shape->img_x / (0.3 + 0.8)) - 0.8;
	mouse_im = (double)y / (shape->img_y / (2.0 + 0.8)) - 0.8;
	shape->c_r = mouse_re;
	shape->c_i = mouse_im;
	ft_display(shape);
	return (0);
}

int			ft_key_funct(int key, t_shape *shape)
{
	ft_clear(shape);
	if (key == 12)
		shape->iter += 100.0;
	if (key == 49)
		ft_reset_fract(shape);
	if (key == 53)
		exit(0);
	ft_display(shape);
	return (0);
}

int			ft_mouse_funct(int mouse, int x, int y, t_shape *shape)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = (double)x / (shape->img_x / (shape->x2 - shape->x1)) + shape->x1;
	mouse_im = (double)y / (shape->img_y / (shape->y2 - shape->y1)) + shape->y1;
	ft_clear(shape);
	if (mouse == 1 || mouse == 5)
	{
		shape->iter += 1.0;
		shape->zoom *= 2.0;
		apply_zoom(shape, mouse_re, mouse_im, 2.0);
	}
	if (mouse == 4)
	{
		shape->iter -= 1;
		shape->zoom -= 1;
		shape->x1 = x + shape->zoom;
		shape->x2 = x - shape->zoom;
		shape->y1 = y + shape->zoom;
		shape->y2 = y - shape->zoom;
	}
	ft_display(shape);
	return (0);
}
