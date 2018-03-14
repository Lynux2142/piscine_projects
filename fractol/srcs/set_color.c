/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 09:35:26 by lguiller          #+#    #+#             */
/*   Updated: 2018/03/14 12:20:33 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		ft_calc_color(int col)
{
	return (ft_couleur(col, col, col));
}

void			ft_set_color(t_shape *shape, t_fract f)
{
	if (shape->color == 1)
		fill_pixel(shape, f.draw.x, f.draw.y,
		(int)(f.i / 75.25 * (255.0 * 255.0 * 255.0)));
	if (shape->color == 2)
		fill_pixel(shape, f.draw.x, f.draw.y,
		ft_couleur(255 - (int)(f.i * 255 * shape->iter),
		255 - (int)(f.i * 255 * shape->iter), (int)(f.i * 255 * shape->iter)));
	if (shape->color == 3)
		fill_pixel(shape, f.draw.x, f.draw.y,
		ft_calc_color(255 - (int)(f.i * 255 / shape->iter)));
	if (shape->color == 4)
		fill_pixel(shape, f.draw.x, f.draw.y,
		ft_couleur((int)(f.i * 255 / shape->iter), 0, 0));
	if (shape->color == 5)
		fill_pixel(shape, f.draw.x, f.draw.y,
		ft_couleur(0, (int)(f.i * 255 / shape->iter), 0));
	if (shape->color == 6)
		fill_pixel(shape, f.draw.x, f.draw.y,
		ft_couleur(0, 0, (int)(f.i * 255 / shape->iter)));
}
