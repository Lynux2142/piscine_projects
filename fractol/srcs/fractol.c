/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 12:29:20 by lguiller          #+#    #+#             */
/*   Updated: 2018/03/13 12:24:11 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_display(t_shape *shape)
{
	t_funct draw_f;

	draw_f = get_f_funct(shape->fract_name);
	draw_f(shape);
	mlx_put_image_to_window(shape->mlx, shape->win, shape->img, 0, 0);
}

int		main(int ac, char **av)
{
	t_shape	shape;
	t_funct	draw_f;

	if (ac != 2 || get_f_funct(av[1]) == NULL)
		ft_usage();
	shape.fract_name = av[1];
	ft_set_values(&shape);
	shape.win_x = 800;
	shape.win_y = 600;
	shape.zoom = 250.0;
	shape.mlx = mlx_init();
	shape.win = mlx_new_window(shape.mlx, shape.win_x, shape.win_y, "test");
	shape.c_r = -0.8;
	shape.c_i = 0.156;
	draw_f = get_f_funct(av[1]);
	draw_f(&shape);
	mlx_put_image_to_window(shape.mlx, shape.win, shape.img, 0, 0);
	if (ft_strcmp(shape.fract_name, "fract2") == 0)
		mlx_hook(shape.win, 6, (1L << 6), ft_var_julia, &shape);
	mlx_key_hook(shape.win, ft_key_funct, &shape);
	mlx_mouse_hook(shape.win, ft_mouse_funct, &shape);
	mlx_loop(shape.mlx);
	return (0);
}
