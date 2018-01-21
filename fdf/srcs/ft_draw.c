/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 10:04:09 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/20 18:01:36 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fdf.h"
#include "mlx.h"
#include "math.h"
#include <stdlib.h>

void		fill_pixel(t_shape *ptr, int x, int y, int color)
{
	((char *)(ptr->data))[(x * 4) + (y * ptr->win_y * 4)] =
		(char)color;
	((char *)(ptr->data))[((x * 4) + (y * ptr->win_y * 4)) + 1] =
		(char)(color >> 8);
	((char *)(ptr->data))[((x * 4) + (y * ptr->win_y * 4)) + 2] =
		(char)(color >> 16);
}

int			ft_couleur(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | (blue));
}

void		ft_draw_segment(t_shape *shape, t_link *xy1, t_link *xy2, int couleur)
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;
	int	dx;
	int	dy;
	int	e;

	x1 = xy1->u;
	y1 = xy1->v;
	x2 = xy2->u;
	y2 = xy2->v;
	if ((dx = x2 - x1) != 0)
	{
		if (dx > 0)
		{
			if ((dy = y2 - y1) != 0)
			{
				if (dy > 0)
				{
					if (dx >= dy)
					{
						e = dx;
						dx = dx * 2;
						dy = dy * 2;
						while (x1++ != x2)
						{
//							mlx_pixel_put(shape->mlx, shape->win, x1, y1, couleur);
							fill_pixel(shape, x1, y1, couleur);
							if ((e = e - dy) < 0)
							{
								y1++;
								e = e + dx;
							}
						}
					}
					else
					{
						e = dy;
						dy = dy * 2;
						dx = dx * 2;
						while (y1++ != y2)
						{
//							mlx_pixel_put(shape->mlx, shape->win, x1, y1, couleur);
							fill_pixel(shape, x1, y1, couleur);
							if ((e = e - dx) < 0)
							{
								x1++;
								e = e + dy;
							}
						}
					}
				}
				else
				{
					if (dx >= (-dy))
					{
						e = dx;
						dx = dx * 2;
						dy = dy * 2;
						while (x1++ != x2)
						{
//							mlx_pixel_put(shape->mlx, shape->win, x1, y1, couleur);
							fill_pixel(shape, x1, y1, couleur);
							if ((e = e + dy) < 0)
							{
								y1--;
								e = e + dy;
							}
						}
					}
					else
					{
						e = dy;
						dy = dy * 2;
						dx = dx * 2;
						while (y1-- != y2)
						{
//							mlx_pixel_put(shape->mlx, shape->win, x1, y1, couleur);
							fill_pixel(shape, x1, y1, couleur);
							if ((e = e + dy) > 0)
							{
								x1++;
								e = e + dy;
							}
						}
					}
				}
			}
			else
			{
				while (x1++ != x2)
//					mlx_pixel_put(shape->mlx, shape->win, x1, y1, couleur);
					fill_pixel(shape, x1, y1, couleur);
			}
		}
		else
		{
			if ((dy = y2 - y1) != 0)
			{
				if (dy > 0)
				{
					if ((-dx) >= dy)
					{
						e = dx;
						dx = dx * 2;
						dy = dy * 2;
						while (x1-- != x2)
						{
//							mlx_pixel_put(shape->mlx, shape->win, x1, y1, couleur);
							fill_pixel(shape, x1, y1, couleur);
							if ((e = e + dy) >= 0)
							{
								y1++;
								e = e + dx;
							}
						}
					}
					else
					{
						e = dy;
						dy = dy * 2;
						dx = dx * 2;
						while (y1++ != y2)
						{
//							mlx_pixel_put(shape->mlx, shape->win, x1, y1, couleur);
							fill_pixel(shape, x1, y1, couleur);
							if ((e = e + dx) <= 0)
							{
								x1--;
								e = e + dy;
							}
						}
					}
				}
				else
				{
					if (dx <= dy)
					{
						e = dx;
						dx = dx * 2;
						dy = dy * 2;
						while (x1-- != x2)
						{
//							mlx_pixel_put(shape->mlx, shape->win, x1, y1, couleur);
							fill_pixel(shape, x1, y1, couleur);
							if ((e = e - dy) >= 0)
							{
								y1--;
								e = e + dx;
							}
						}
					}
					else
					{
						e = dy;
						dy = dy * 2;
						dx = dx * 2;
						while (y1-- != y2)
						{
//							mlx_pixel_put(shape->mlx, shape->win, x1, y1, couleur);
							fill_pixel(shape, x1, y1, couleur);
							if ((e = e - dx) >= 0)
							{
								x1--;
								e = e + dy;
							}
						}
					}
				}
			}
			else
			{
				while (x1-- != x2)
//					mlx_pixel_put(shape->mlx, shape->win, x1, y1, couleur);
					fill_pixel(shape, x1, y1, couleur);
			}
		}
	}
	else
	{
		if ((dy = y2 - y1) != 0)
		{
			if (dy > 0)
			{
				while (y1++ != y2)
//					mlx_pixel_put(shape->mlx, shape->win, x1, y1, couleur);
					fill_pixel(shape, x1, y1, couleur);
			}
			else
			{
				while (y1-- != y2)
//					mlx_pixel_put(shape->mlx, shape->win, x1, y1, couleur);
					fill_pixel(shape, x1, y1, couleur);
			}
		}
	}
//	mlx_pixel_put(shape->mlx, shape->win, x1, y1, couleur);
	fill_pixel(shape, x1, y1, couleur);
}

void		ft_draw_funct(t_shape *shape)
{
	t_slist		*current;
	t_slist		*current2;
	t_slist		*prev_y;
	t_slist		*prev_x;
	t_link		*ptr;
	int			color;

	prev_y = NULL;
	prev_x = NULL;
	current = shape->list;
	while (current)
	{
		current2 = current;
		while (current2)
		{
			ptr = (t_link *)current2->link;
			color = (ptr->color) ? ptr->color : ft_couleur(ptr->x * 10, ptr->y * 20, 100);
			if (prev_y)
			{
				ft_draw_segment(shape, (t_link *)current2->link,
					(t_link *)prev_y->link, color);
				prev_y = prev_y->next_x;
			}
			if (prev_x)
			{
				ft_draw_segment(shape, (t_link *)current2->link,
						(t_link *)prev_x->link, color);
				prev_x = prev_x->next_x;
			}
			prev_x = current2;
			current2 = current2->next_x;
		}
		prev_x = NULL;
		prev_y = current;
		current = current->next_y;
	}
}

void		ft_projection(t_shape *shape)
{
	t_slist		*current;
	t_slist		*current2;
	t_link		*ptr;
	int			agr;
	int			dec;

	current = shape->list;
	dec = 50;
	agr = 2;
	while (current)
	{
		current2 = current;
		while (current2)
		{
			ptr = (t_link *)current2->link;
			ptr->u = dec + agr * (((ptr->x) 
						* cos(shape->coef_a + shape->coef_x)) + ((ptr->y)
						* cos(shape->coef_a + shape->coef_y)) + ((ptr->z)
						* cos(shape->coef_a - shape->coef_z)));
			ptr->v = (dec * 10) + agr * (((ptr->x)
						* sin(shape->coef_a + shape->coef_x)) + ((ptr->y)
						* sin(shape->coef_a + shape->coef_y)) + ((ptr->z)
						* sin(shape->coef_a - shape->coef_z)));
			current2 = current2->next_x;
		}
		current = current->next_y;
	}
	ft_draw_funct(shape);
}

int			ft_key_funct(int key, t_shape *shape)
{
	ft_putstr("keycode : ");
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 12)
		shape->coef_x += 1;
	if (key == 0)
		shape->coef_x -= 1;
	if (key == 13)
		shape->coef_y += 1;
	if (key == 1)
		shape->coef_y -= 1;
	if (key == 14)
		shape->coef_z += 1;
	if (key == 2)
		shape->coef_z -= 1;
	if (key == 15)
		shape->coef_a += 1;
	if (key == 3)
		shape->coef_a -= 1;
	if (key == 49)
	{
		shape->coef_x = 31;
		shape->coef_y = 13;
		shape->coef_z = 33;
		shape->coef_a = 0;
	}
	if (key == 36)
	{
		ft_putstr("coef_x : ");
		ft_putnbr(shape->coef_x);
		ft_putchar('\n');
		ft_putstr("coef_y : ");
		ft_putnbr(shape->coef_y);
		ft_putchar('\n');
		ft_putstr("coef_z : ");
		ft_putnbr(shape->coef_z);
		ft_putchar('\n');
		ft_putstr("coef_a : ");
		ft_putnbr(shape->coef_a);
		ft_putchar('\n');
	}
	if (key == 53)
		exit(1);
	mlx_clear_window(shape->mlx, shape->win);
	mlx_destroy_image(shape->mlx, shape->img);
	shape->img = mlx_new_image(shape->mlx, shape->win_x, shape->win_y);
	shape->data = mlx_get_data_addr(shape->img, &shape->bpp, &shape->sizeline, &shape->endian);
	ft_projection(shape);
	mlx_put_image_to_window(shape->mlx, shape->win, shape->img, 0, 0);
	return (0);
}

void		ft_draw(t_slist **list)
{
	t_shape		shape;

	shape.mlx = mlx_init();
	shape.win_x = 2000;
	shape.win_y = 1000;
	shape.win = mlx_new_window(shape.mlx, shape.win_x, shape.win_y, "test");
	shape.img = mlx_new_image(shape.mlx, shape.win_x, shape.win_y);
	shape.data = mlx_get_data_addr(shape.img, &shape.bpp, &shape.sizeline, &shape.endian);
	shape.list = *list;
	shape.coef_x = 31;
	shape.coef_y = 13;
	shape.coef_z = 33;
	shape.coef_a = 0;
	ft_projection(&shape);
	mlx_put_image_to_window(shape.mlx, shape.win, shape.img, 0, 0);
	mlx_key_hook(shape.win, ft_key_funct, &shape);
	mlx_loop(shape.mlx);
}
