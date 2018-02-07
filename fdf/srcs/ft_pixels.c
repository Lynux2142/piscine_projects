/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixels.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:25:18 by lguiller          #+#    #+#             */
/*   Updated: 2018/02/07 15:38:12 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fill_pixel(t_shape *shape, int x, int y, int color)
{
	if ((y >= 0 && y < shape->img_y)
	&& (x >= 0 && x < shape->img_x))
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

int			ft_couleur(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | (blue));
}

void		projection_calcul(t_shape *shape, t_link *ptr)
{
	double x;
	double y;
	double z;

	ptr->x -= ((shape->x_max) / 2);
	ptr->y -= ((shape->y_max) / 2);
	x = ((ptr->x) * cos(shape->rot)) - ((ptr->y) * sin(shape->rot));
	y = ((ptr->x) * sin(shape->rot)) + ((ptr->y) * cos(shape->rot));
	z = ptr->z;
	ptr->u = shape->agr * (((x) * cos(shape->coef_a + shape->coef_x))
			+ ((y) * cos(shape->coef_a + shape->coef_y))
			+ ((z) * cos(shape->coef_a - shape->coef_z)));
	ptr->v = shape->agr * (((x) * sin(shape->coef_a + shape->coef_x))
			+ ((y) * sin(shape->coef_a + shape->coef_y))
			+ ((z) * sin(shape->coef_a - shape->coef_z)));
	ptr->x += ((shape->x_max) / 2);
	ptr->y += ((shape->y_max) / 2);
}

int			ft_calcul_color(t_slist *first, t_slist *second)
{
	t_link	*ptr;

	ptr = (t_link *)first->link;
	if (first->link->color && second->link->color)
	{
		if (((t_link *)first->link)->z < ((t_link *)second->link)->z)
			return (((t_link *)second->link)->color);
		else
			return (((t_link *)first->link)->color);
	}
	else
		return (ft_couleur(ptr->x * 10, ptr->y * 20, 200));
}
