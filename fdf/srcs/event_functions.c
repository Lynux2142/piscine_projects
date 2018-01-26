/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:35:37 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/26 17:07:18 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_mouse_funct(int mouse, int x, int y, t_shape *shape)
{
	(void)x;
	(void)y;
	if (mouse == 5 || mouse == 4)
	{
		mlx_clear_window(shape->mlx, shape->win);
		mlx_destroy_image(shape->mlx, shape->img);
		shape->img = mlx_new_image(shape->mlx, shape->img_x, shape->img_y);
		shape->data = mlx_get_data_addr(shape->img, &shape->bpp,
				&shape->sizeline, &shape->endian);
		if (mouse == 5)
			shape->agr += 1;
		if (mouse == 4)
			shape->agr -= 1;
		ft_projection(shape);
		mlx_put_image_to_window(shape->mlx, shape->win, shape->img, 0, 0);
	}
	return (0);
}

void		move_axe_x(int key, t_shape *shape)
{
	if (key == 12)
	{
		shape->coef_x += 1;
		shape->coef_z -= 1;
	}
	if (key == 0)
	{
		shape->coef_x -= 1;
		shape->coef_z += 1;
	}
}

void		move_axe_y(int key, t_shape *shape)
{
	if (key == 13)
	{
		shape->coef_y += 1;
		shape->coef_z -= 1;
	}
	if (key == 1)
	{
		shape->coef_y -= 1;
		shape->coef_z += 1;
	}
}

void		move_others(int key, t_shape *shape)
{
	if (key == 15)
		shape->coef_a += 1;
	if (key == 3)
		shape->coef_a -= 1;
	if (key == 69)
		shape->agr += 1;
	if (key == 78)
		shape->agr -= 1;
	if (key == 49)
	{
		shape->coef_x = 31;
		shape->coef_y = 13;
		shape->coef_z = 33;
		shape->coef_a = 0;
	}
}

int			ft_key_funct(int key, t_shape *shape)
{
	mlx_clear_window(shape->mlx, shape->win);
	mlx_destroy_image(shape->mlx, shape->img);
	shape->img = mlx_new_image(shape->mlx, shape->img_x, shape->img_y);
	shape->data = mlx_get_data_addr(shape->img, &shape->bpp,
			&shape->sizeline, &shape->endian);
	if (key == 12 || key == 0)
		move_axe_x(key, shape);
	if (key == 13 || key == 1)
		move_axe_y(key, shape);
	if (key == 15 || key == 3 || key == 69 || key == 78 || key == 49)
		move_others(key, shape);
	if (key == 53)
		exit(1);
	ft_projection(shape);
	mlx_put_image_to_window(shape->mlx, shape->win, shape->img, 0, 0);
	return (0);
}
