/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 12:29:20 by lguiller          #+#    #+#             */
/*   Updated: 2018/02/19 15:34:57 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_usage(void)
{
	ft_putendl("usage: ./fractol [fract_name]");
	ft_putendl("	- fract_name: [fract1 / fract2 / fract3]");
	exit(1);
}

t_funct	get_f_funct(char *name_f)
{
	const char		*f_name[] = {"fract1", "fract2", "fract3"};
	const t_funct	funct_name[] = {&fract1, &fract2, &fract3};
	int				i;

	i = -1;
	while (++i < 3)
		if (ft_strequ(name_f, f_name[i]) == 1)
			return (funct_name[i]);
	return (NULL);
}

double	ft_interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	apply_zoom(t_shape *shape, double mouse_re,
		double mouse_im, double zoom_factor)
{
	double	interpolation;

	interpolation = 1.0 / zoom_factor;
	shape->x1 = ft_interpolate(mouse_re, shape->x1, interpolation);
	shape->x2 = ft_interpolate(mouse_re, shape->x2, interpolation);
	shape->y1 = ft_interpolate(mouse_im, shape->y1, interpolation);
	shape->y2 = ft_interpolate(mouse_im, shape->y2, interpolation);
}
