/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 11:10:01 by lguiller          #+#    #+#             */
/*   Updated: 2018/02/10 11:46:21 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	ft_usage(void)
{
	ft_putendl("usage: ./fractol [fract_name]");
	ft_putendl("	- fract_name: [mandelbrot / julia]");
	exit(1);
}

void	fill_pixel(t_shape *shape, int x, int y, int color)
{
	if ((y >= 0 && y < shape->img_y)
	&& (x > 0 && x < shape->img_x))
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

int		ft_couleur(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | (blue));
}

double	ft_pow(double nb, int power)
{
	double	value;
	int		i;

	value = 1.0;
	i = -1;
	while (++i < power)
		value *= nb;
	return (value);
}

void	mandelbrot(t_shape *shape)
{
	t_fract	fract;
	int		x;
	int		y;
	double	image_x;
	double	image_y;
	double	tmp;

	shape->img_x = shape->win_x;
	shape->img_y = shape->win_y;
	shape->img = mlx_new_image(shape->mlx, shape->img_x, shape->img_y);
	shape->data = mlx_get_data_addr(
			shape->img, &shape->bpp, &shape->sizeline, &shape->endian);
	image_x = (shape->x2 - shape->x1) * shape->zoom;
	image_y = (shape->y2 - shape->y1) * shape->zoom;
	x = -1;
	while (++x < shape->img_x)
	{
		y = -1;
		while (++y < shape->img_y)
		{
			fract.c_r = (double)x / shape->zoom + shape->x1;
			fract.c_i = (double)y / shape->zoom + shape->y1;
			fract.z_r = 0.0;
			fract.z_i = 0.0;
			fract.i = 0.0;
			while ((ft_pow(fract.z_r, 2) + ft_pow(fract.z_i, 2)) < 4.0
					&& fract.i < shape->iter)
			{
				tmp = fract.z_r;
				fract.z_r =
					ft_pow(fract.z_r, 2) - ft_pow(fract.z_i, 2) + fract.c_r;
				fract.z_i = 2.0 * fract.z_i * tmp + fract.c_i;
				++fract.i;
			}
			if (fract.i == shape->iter)
				fill_pixel(shape, x, y, 0x000000);
			else
				fill_pixel(shape, x, y,
						ft_couleur((int)(fract.i * 255.0 / shape->iter), 0, 0));
		}
	}
}

void	julia(t_shape *shape)
{
	t_fract	fract;
	int		x;
	int		y;
	double	image_x;
	double	image_y;
	double	tmp;

	shape->img_x = shape->win_x;
	shape->img_y = shape->win_y;
	shape->img = mlx_new_image(shape->mlx, shape->img_x, shape->img_y);
	shape->data = mlx_get_data_addr(
			shape->img, &shape->bpp, &shape->sizeline, &shape->endian);
	image_x = (shape->x2 - shape->x1) * (shape->zoom);
	image_y = (shape->y2 - shape->y1) * (shape->zoom);
	x = -1;
	while (++x < image_x)
	{
		y = -1;
		while (++y < image_y)
		{
			fract.c_r = 0.285;
			fract.c_i = 0.01;
			fract.z_r = (double)x / (shape->zoom) + shape->x1;
			fract.z_i = (double)y / (shape->zoom) + shape->y1;
			fract.i = 0.0;
			while ((ft_pow(fract.z_r, 2) + ft_pow(fract.z_i, 2)) < 4.0
					&& fract.i < shape->iter)
			{
				tmp = fract.z_r;
				fract.z_r =
					ft_pow(fract.z_r, 2) - ft_pow(fract.z_i, 2) + fract.c_r;
				fract.z_i = 2.0 * fract.z_i * tmp + fract.c_i;
				++fract.i;
			}
			if (fract.i == shape->iter)
				fill_pixel(shape, x, y, 0x000000);
			else
				fill_pixel(shape, x, y,
						ft_couleur(0, 0, (int)(fract.i * 255 / shape->iter)));
		}
	}
}

t_funct	get_fract_funct(char *name_fract)
{
	const char		*fract_name[] = {"mandelbrot", "julia"};
	const t_funct	funct_name[] = {&mandelbrot, &julia};
	int				i;

	i = -1;
	while (++i < 2)
		if (ft_strequ(name_fract, fract_name[i]) == 1)
			return (funct_name[i]);
	return (NULL);
}

int		ft_key_funct(int key, t_shape *shape)
{
	t_funct	draw_fract;

	mlx_clear_window(shape->mlx, shape->win);
	mlx_destroy_image(shape->mlx, shape->img);
	shape->img = mlx_new_image(shape->mlx, shape->img_x, shape->img_y);
	shape->data = mlx_get_data_addr(shape->img, &shape->bpp,
			&shape->sizeline, &shape->endian);
	if (key == 12)
		shape->iter += 100.0;
	if (key == 49)
	{
		if (ft_strequ("mandelbrot", shape->fract_name) == 1)
		{
			shape->zoom = 500.0;
			shape->iter = 50.0;
			shape->basic.x1 = -2.2;
			shape->basic.x2 = 2.2;
			shape->basic.y1 = -1.2;
			shape->basic.y2 = 1.2;
			shape->x1 = shape->basic.x1;
			shape->x2 = shape->basic.x2;
			shape->y1 = shape->basic.y1;
			shape->y2 = shape->basic.y2;
		}
		else if (ft_strequ("julia", shape->fract_name) == 1)
		{
			shape->zoom = 500.0;
			shape->iter = 150.0;
			shape->x1 = -1.6;
			shape->x2 = 2.0;
			shape->y1 = -1.2;
			shape->y2 = 1.2;
		}
	}
	if (key == 126)
	{
		shape->y1 -= 0.05;
		shape->y2 -= 0.05;
	}
	if (key == 125)
	{
		shape->y1 += 0.05;
		shape->y2 += 0.05;
	}
	if (key == 123)
	{
		shape->x1 -= 0.05;
		shape->x2 -= 0.05;
	}
	if (key == 124)
	{
		shape->x1 += 0.05;
		shape->x2 += 0.05;
	}
	if (key == 53)
		exit(0);
	draw_fract = get_fract_funct(shape->fract_name);
	draw_fract(shape);
	mlx_put_image_to_window(shape->mlx, shape->win, shape->img, 0, 0);
	return (0);
}

double	ft_interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	apply_zoom(t_shape *shape, double mouseRe, double mouseIm, double zoom_factor)
{
	double	interpolation;

	interpolation = 1.0 / zoom_factor;
	shape->x1 = ft_interpolate(mouseRe, shape->x1, interpolation);
	shape->x2 = ft_interpolate(mouseRe, shape->x2, interpolation);
	shape->y1 = ft_interpolate(mouseIm, shape->y1, interpolation);
	shape->y2 = ft_interpolate(mouseIm, shape->y2, interpolation);
}

int		ft_mouse_funct(int mouse, int x, int y, t_shape *shape)
{
	t_funct	draw_fract;
	double	mouseRe;
	double	mouseIm;

	mouseRe = (double)x / (shape->img_x / (shape->x2 - shape->x1)) + shape->x1;
	mouseIm = (double)y / (shape->img_y / (shape->y2 - shape->y1)) + shape->y1;
	mlx_clear_window(shape->mlx, shape->win);
	mlx_destroy_image(shape->mlx, shape->img);
	shape->img = mlx_new_image(shape->mlx, shape->img_x, shape->img_y);
	shape->data = mlx_get_data_addr(shape->img, &shape->bpp,
			&shape->sizeline, &shape->endian);
	if (mouse == 1)
	{
		shape->iter += 1.0;
		shape->zoom *= 2.0;
		apply_zoom(shape, mouseRe, mouseIm, 2.0);
	}
	if (mouse == 4)
	{
		shape->iter -= 1;
		shape->zoom -= 1;
		shape->x1 = x + shape->zoom;
		shape->x2 = x - shape->zoom;
		shape->y1 = y + shape->zoom;
		shape->y2 = y - shape->zoom;
	}
	draw_fract = get_fract_funct(shape->fract_name);
	draw_fract(shape);
	mlx_put_image_to_window(shape->mlx, shape->win, shape->img, 0, 0);
	return (0);
}

void	ft_set_values(t_shape *shape)
{
	if (ft_strequ("mandelbrot", shape->fract_name) == 1)
	{
		shape->iter = 50.0;
		shape->basic.x1 = -2.2;
		shape->basic.x2 = 2.2;
		shape->basic.y1 = -1.2;
		shape->basic.y2 = 1.2;
		shape->x1 = shape->basic.x1;
		shape->x2 = shape->basic.x2;
		shape->y1 = shape->basic.y1;
		shape->y2 = shape->basic.y2;
	}
	else if (ft_strequ("julia", shape->fract_name) == 1)
	{
		shape->iter = 150.0;
		shape->x1 = -1.6;
		shape->x2 = 1.6;
		shape->y1 = -1.2;
		shape->y2 = 1.2;
	}
}

int		main(int ac, char **av)
{
	t_shape	shape;
	t_funct	draw_fract;

	if (ac != 2 || get_fract_funct(av[1]) == NULL)
		ft_usage();
	shape.fract_name = av[1];
	ft_set_values(&shape);
	shape.win_x = 1600;
	shape.win_y = 1200;
	shape.zoom = 500.0;
	shape.mlx = mlx_init();
	shape.win = mlx_new_window(shape.mlx, shape.win_x, shape.win_y, "test");
	draw_fract = get_fract_funct(av[1]);
	draw_fract(&shape);
	mlx_put_image_to_window(shape.mlx, shape.win, shape.img, 0, 0);
	mlx_key_hook(shape.win, ft_key_funct, &shape);
	mlx_mouse_hook(shape.win, ft_mouse_funct, &shape);
	mlx_loop(shape.mlx);
	return (0);
}
