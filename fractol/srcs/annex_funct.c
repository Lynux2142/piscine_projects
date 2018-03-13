/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 12:29:20 by lguiller          #+#    #+#             */
/*   Updated: 2018/03/13 12:50:54 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_usage(void)
{
	ft_putendl("usage: ./fractol [fract_name]");
	ft_putendl("	- fract_name: [fract1 / fract2 / fract3]");
	exit(1);
}

t_funct			get_f_funct(char *name_f)
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

static double	ft_inter_in(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

static double	ft_inter_out(double start, double end, double interpolation)
{
	return (start + ((end - start) / interpolation));
}

void			apply_zoom(t_shape *shape, double mouse_re,
		double mouse_im, double zoom_factor)
{
	double	interpolation;

	interpolation = 1.0 / zoom_factor;
	if (shape->in_out == 5 || shape->in_out == 1)
	{
		shape->x1 = ft_inter_in(mouse_re, shape->x1, interpolation);
		shape->x2 = ft_inter_in(mouse_re, shape->x2, interpolation);
		shape->y1 = ft_inter_in(mouse_im, shape->y1, interpolation);
		shape->y2 = ft_inter_in(mouse_im, shape->y2, interpolation);
	}
	else if (shape->in_out == 4 || shape->in_out == 2)
	{
		shape->x1 = ft_inter_out(mouse_re, shape->x1, interpolation);
		shape->x2 = ft_inter_out(mouse_re, shape->x2, interpolation);
		shape->y1 = ft_inter_out(mouse_im, shape->y1, interpolation);
		shape->y2 = ft_inter_out(mouse_im, shape->y2, interpolation);
	}
}
