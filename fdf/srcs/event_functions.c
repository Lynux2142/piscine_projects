/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:35:37 by lguiller          #+#    #+#             */
/*   Updated: 2018/04/05 15:25:28 by lguiller         ###   ########.fr       */
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
			shape->agr *= 1.1;
			shape->speed += 2;
		}
		if (mouse == 4)
		{
			shape->agr /= 1.1;
			shape->speed -= 2;
		}
		ft_projection(shape);
		mlx_put_image_to_window(shape->mlx, shape->win, shape->img, 0, 0);
	}
	return (0);
}

static void		ft_rotate(int key, t_shape *shape)
{
	if (key == 2)
	{
		if (shape->rot < 350.0 * M_PI / 180.0)
			shape->rot += 10.0 * M_PI / 180.0;
		else
			shape->rot = 0.0 * M_PI / 180.0;
	}
	if (key == 0)
	{
		if (shape->rot > 0.0 * M_PI / 180.0)
			shape->rot -= 10.0 * M_PI / 180.0;
		else
			shape->rot = 350.0 * M_PI / 180.0;
	}
}

static void		move_others(int key, t_shape *shape)
{
	if (key == 24)
		shape->agr *= 1.1;
	if (key == 27)
		shape->agr /= 1.1;
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
		shape->rot = 0.0 * M_PI / 180.0;
		shape->coef_x = 0.0 * M_PI / 180.0;
		shape->coef_y = 120.0 * M_PI / 180.0;
		shape->coef_z = 120.0 * M_PI / 180.0;
		shape->coef_a = 30.0 * M_PI / 180.0;
	}
}

static void		ft_auto_funct(int key, t_shape *shape)
{
	if (key == 36)
	{
		if (shape->ok_rotate != 1)
			shape->ok_rotate = 1;
		else
			shape->ok_rotate = 0;
	}
	if (key == 258)
	{
		if (shape->ok_z != 1)
			shape->ok_z = 1;
		else
			shape->ok_z = 0;
	}
}

int				ft_key_funct(int key, t_shape *shape)
{
	mlx_clear_window(shape->mlx, shape->win);
	mlx_destroy_image(shape->mlx, shape->img);
	shape->img = mlx_new_image(shape->mlx, shape->img_x, shape->img_y);
	shape->data = mlx_get_data_addr(shape->img, &shape->bpp,
			&shape->sizeline, &shape->endian);
	if (key == KEY_A || key == KEY_D)
		ft_rotate(key, shape);
	if (key == EQUAL || key == MINUS || key == SPACE
			|| (key >= L_ARROW && key <= U_ARROW))
		move_others(key, shape);
	if (key == ESC)
	{
		ft_clear_list(&shape->list);
		exit(0);
	}
	if (key == ENTER || key == R_SHIFT)
		ft_auto_funct(key, shape);
	ft_projection(shape);
	mlx_put_image_to_window(shape->mlx, shape->win, shape->img, 0, 0);
	return (0);
}
