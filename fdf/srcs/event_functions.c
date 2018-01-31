/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:35:37 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/31 12:12:49 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_mouse_funct(int mouse, int x, int y, t_shape *shape)
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
		{
			shape->agr += 1;
			shape->speed += 2;
		}
		if (mouse == 4)
		{
			shape->agr -= 1;
			shape->speed -= 2;
		}
		ft_projection(shape);
		mlx_put_image_to_window(shape->mlx, shape->win, shape->img, 0, 0);
	}
	return (0);
}

static void		ft_rotate(int key, t_shape *shape)
{
	if (key == 88)
		shape->rot += 30 * 0.0174533;
	if (key == 86)
		shape->rot -= 30 * 0.0174533;
}

static void		move_others(int key, t_shape *shape)
{
	if (key == 69)
		shape->agr += 1;
	if (key == 78)
		shape->agr -= 1;
	if (key == 124)
		shape->start_x += shape->speed;
	if (key == 123)
		shape->start_x -= shape->speed;
	if (key == 125)
		shape->start_y -= shape->speed;
	if (key == 126)
		shape->start_y += shape->speed;
	if (key == 49)
	{
		shape->coef_x = 120 * 0.0174533;
		shape->coef_y = 120 * 0.0174533;
		shape->coef_z = 121 * 0.0174533;
		shape->coef_a = 30 * 0.0174533;
		shape->rot = 270 * 0.0174533;
	}
}

int				ft_key_funct(int key, t_shape *shape)
{
	mlx_clear_window(shape->mlx, shape->win);
	mlx_destroy_image(shape->mlx, shape->img);
	shape->img = mlx_new_image(shape->mlx, shape->img_x, shape->img_y);
	shape->data = mlx_get_data_addr(shape->img, &shape->bpp,
			&shape->sizeline, &shape->endian);
	if (key == 86 || key == 88)
		ft_rotate(key, shape);
	if (key == 15 || key == 3 || key == 69 || key == 78 || key == 49
			|| (key >= 123 && key <= 126))
		move_others(key, shape);
	if (key == 53)
		exit(1);
	ft_projection(shape);
	mlx_put_image_to_window(shape->mlx, shape->win, shape->img, 0, 0);
	return (0);
}
