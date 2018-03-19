/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:51:42 by lguiller          #+#    #+#             */
/*   Updated: 2018/03/19 17:21:49 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_put_keybord(t_shape *shape)
{
	int y;

	mlx_string_put(shape->mlx, shape->win, 830, (y = 180), RED, "Mooving:");
	mlx_string_put(shape->mlx, shape->win, 850, y += 20, RED,
			"Up arrow    : move up");
	mlx_string_put(shape->mlx, shape->win, 850, y += 20, RED,
			"Down arrow  : move down");
	mlx_string_put(shape->mlx, shape->win, 850, y += 20, RED,
			"Left arrow  : move left");
	mlx_string_put(shape->mlx, shape->win, 850, y += 20, RED,
			"Right arrow : move right");
	mlx_string_put(shape->mlx, shape->win, 830, y += 40, RED, "Iterations:");
	mlx_string_put(shape->mlx, shape->win, 850, y += 20, RED,
			"\"-\"         : decrease iterations");
	mlx_string_put(shape->mlx, shape->win, 850, y += 20, RED,
			"\"=\"         : increase iterations");
	mlx_string_put(shape->mlx, shape->win, 830, y += 40, RED, "Other:");
	mlx_string_put(shape->mlx, shape->win, 850, y += 20, RED,
			"Enter       : change color set");
	mlx_string_put(shape->mlx, shape->win, 850, y += 20, RED,
			"Right shift : lock/unlock variations");
	mlx_string_put(shape->mlx, shape->win, 850, y += 20, RED,
			"Space bar   : restore default");
	mlx_string_put(shape->mlx, shape->win, 850, y += 20, RED,
			"\"f\"         : generate .fdf");
}

void		ft_put_infos(t_shape *shape)
{
	int x;
	int y;

	mlx_string_put(shape->mlx, shape->win, (x = 1110),
			(y = 40), RED, "SHORTCUTS SETTINGS");
	mlx_string_put(shape->mlx, shape->win, 945, y += 80, RED, "KEYBOARD");
	mlx_string_put(shape->mlx, shape->win, 1395, y, RED, "MOUSE");
	mlx_string_put(shape->mlx, shape->win, 1280, y += 60, RED, "Zoom:");
	mlx_string_put(shape->mlx, shape->win, 1300, y += 20, RED,
			"MWHEELDOWN : zoom in");
	mlx_string_put(shape->mlx, shape->win, 1300, y += 20, RED,
			"MWHEELUP   : zoom out");
	ft_put_keybord(shape);
}
