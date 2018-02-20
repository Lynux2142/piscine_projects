/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:12:30 by lguiller          #+#    #+#             */
/*   Updated: 2018/02/20 09:36:27 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_const_var_1(t_shape *shape, t_draw *draw, t_fract *f)
{
	f->c_r = (double)draw->x / shape->zoom + shape->x1;
	f->c_i = (double)draw->y / shape->zoom + shape->y1;
	f->z_r = 0.0;
	f->z_i = 0.0;
	f->i = 0.0;
}

void		fract1(t_shape *shape)
{
	t_fract	f;

	ft_init(shape, &f.draw);
	while (++f.draw.x < f.draw.image_x)
	{
		f.draw.y = -1;
		while (++f.draw.y < f.draw.image_y)
		{
			ft_const_var_1(shape, &f.draw, &f);
			while ((ft_pow(f.z_r, 2) + ft_pow(f.z_i, 2)) < 4.0
					&& f.i < shape->iter)
			{
				f.draw.tmp = f.z_r;
				f.z_r =
					ft_pow(f.z_r, 2) - ft_pow(f.z_i, 2) + f.c_r;
				f.z_i = 2.0 * f.z_i * f.draw.tmp + f.c_i;
				++f.i;
			}
			if (f.i == shape->iter)
				fill_pixel(shape, f.draw.x, f.draw.y, 0x000000);
			else
				fill_pixel(shape, f.draw.x, f.draw.y,
						ft_couleur((int)(f.i * 255.0 / shape->iter), 0, 0));
		}
	}
}
