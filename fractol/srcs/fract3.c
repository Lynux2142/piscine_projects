/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:14:45 by lguiller          #+#    #+#             */
/*   Updated: 2018/02/20 09:36:42 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_calc_color(int col)
{
	return (ft_couleur(col, col, col));
}

static double	ft_absolute(double nb)
{
	return ((nb < 0.0) ? -nb : nb);
}

static void		ft_const_var_3(t_shape *shape, t_draw *draw, t_fract *f)
{
	f->c_r = (double)draw->x / (shape->zoom) + shape->x1;
	f->c_i = (double)draw->y / (shape->zoom) + shape->y1;
	f->z_r = 0.0;
	f->z_i = 0.0;
	f->i = 0.0;
}

void			fract3(t_shape *shape)
{
	t_fract	f;
	t_draw	draw;

	ft_init(shape, &draw);
	while (++draw.x < draw.image_x)
	{
		draw.y = -1;
		while (++draw.y < draw.image_y)
		{
			ft_const_var_3(shape, &draw, &f);
			while ((ft_pow(f.z_r, 2) + ft_pow(f.z_i, 2)) < 4.0
					&& f.i < shape->iter)
			{
				draw.tmp = ft_pow(f.z_r, 2) - ft_pow(f.z_i, 2) + f.c_r;
				f.z_i = 2.0 * ft_absolute(f.z_r * f.z_i) + f.c_i;
				f.z_r = draw.tmp;
				++f.i;
			}
			if (f.i == shape->iter)
				fill_pixel(shape, draw.x, draw.y, 0x000000);
			else
				fill_pixel(shape, draw.x, draw.y,
						ft_calc_color(255 - (int)(f.i * 255 / shape->iter)));
		}
	}
}
