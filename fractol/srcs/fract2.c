/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:12:23 by lguiller          #+#    #+#             */
/*   Updated: 2018/02/20 09:40:45 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_const_var_2(t_shape *shape, t_draw *draw, t_fract *f)
{
	f->c_r = shape->c_r;
	f->c_i = shape->c_i;
	f->z_r = (double)draw->x / (shape->zoom) + shape->x1;
	f->z_i = (double)draw->y / (shape->zoom) + shape->y1;
	f->i = 0.0;
}

void		fract2(t_shape *shape)
{
	t_fract	f;
	t_draw	draw;

	ft_init(shape, &draw);
	while (++draw.x < draw.image_x)
	{
		draw.y = -1;
		while (++draw.y < draw.image_y)
		{
			ft_const_var_2(shape, &draw, &f);
			while ((ft_pow(f.z_r, 2) + ft_pow(f.z_i, 2)) < 4.0
					&& f.i < shape->iter)
			{
				draw.tmp = f.z_r;
				f.z_r = ft_pow(f.z_r, 2) - ft_pow(f.z_i, 2) + f.c_r;
				f.z_i = 2.0 * f.z_i * draw.tmp + f.c_i;
				++f.i;
			}
			if (f.i == shape->iter)
				fill_pixel(shape, draw.x, draw.y, 0x000000);
			else
				fill_pixel(shape, draw.x, draw.y,
						ft_couleur(0, 0, (int)(f.i * 255 / shape->iter)));
		}
	}
}
