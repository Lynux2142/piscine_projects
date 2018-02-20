/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:17:48 by lguiller          #+#    #+#             */
/*   Updated: 2018/02/19 15:29:18 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init(t_shape *shape, t_draw *draw)
{
	shape->img_x = shape->win_x;
	shape->img_y = shape->win_y;
	shape->img = mlx_new_image(shape->mlx, shape->img_x, shape->img_y);
	shape->data = mlx_get_data_addr(
			shape->img, &shape->bpp, &shape->sizeline, &shape->endian);
	draw->image_x = (shape->x2 - shape->x1) * shape->zoom;
	draw->image_y = (shape->y2 - shape->y1) * shape->zoom;
	draw->x = -1;
}

double	ft_pow(double nb, int power)
{
	double	value;
	int		i;

	value = 1.0;
	i = -1;
	while (++i < power)
		value *= nb;
	return (value);
}

void	fill_pixel(t_shape *shape, int x, int y, int color)
{
	if ((y >= 0 && y < shape->img_y)
	&& (x > 0 && x < shape->img_x))
	{
		if (shape->endian == 0)
		{
			((char *)(shape->data))[((x * 4) + (y * shape->sizeline))] =
				(char)color;
			((char *)(shape->data))[((x * 4) + (y * shape->sizeline)) + 1] =
				(char)(color >> 8);
			((char *)(shape->data))[((x * 4) + (y * shape->sizeline)) + 2] =
				(char)(color >> 16);
			((char *)(shape->data))[((x * 4) + (y * shape->sizeline)) + 3] =
				(char)0;
		}
	}
}

int		ft_couleur(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | (blue));
}

void	ft_set_values(t_shape *shape)
{
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
