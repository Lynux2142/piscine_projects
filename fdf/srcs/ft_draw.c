/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 10:04:09 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/25 15:17:48 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fdf.h"
#include "mlx.h"
#include "math.h"
#include <stdlib.h>
#include <stdio.h>

void		fill_pixel(t_shape *ptr, int x, int y, int color)
{
	if ((((x * 4) + (y * ptr->img_y * 4)) + 3) <= (ptr->img_x * 4) + (ptr->img_y * ptr->sizeline * 4)
			&& (((x * 4) + (y * ptr->img_y * 4)) + 3) >= 0)
	{
		if (ptr->endian == 0)
		{
			((char *)(ptr->data))[((x * 4) + (y * ptr->sizeline))] =
				(char)color;
			((char *)(ptr->data))[((x * 4) + (y * ptr->sizeline)) + 1] =
				(char)(color >> 8);
			((char *)(ptr->data))[((x * 4) + (y * ptr->sizeline)) + 2] =
				(char)(color >> 16);
			((char *)(ptr->data))[((x * 4) + (y * ptr->sizeline)) + 3] =
				(char)0;
		}
		else if (ptr->endian == 1)
		{
			((char *)(ptr->data))[((x * 4) + (y * ptr->sizeline))] =
				(char)0;
			((char *)(ptr->data))[((x * 4) + (y * ptr->sizeline)) + 1] =
				(char)(color >> 16);
			((char *)(ptr->data))[((x * 4) + (y * ptr->sizeline)) + 2] =
				(char)(color >> 8);
			((char *)(ptr->data))[((x * 4) + (y * ptr->sizeline)) + 3] =
				(char)color;
		}
	}
}

int			ft_couleur(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | (blue));
}

void		ft_draw_segment(t_shape *shape, t_link *xy1, t_link *xy2, int col)
{
	t_draw	val;

	val.x1 = xy1->u;
	val.y1 = xy1->v;
	val.x2 = xy2->u;
	val.y2 = xy2->v;
	if ((val.dx = val.x2 - val.x1) != 0)
	{
		if (val.dx > 0)
		{
			if ((val.dy = val.y2 - val.y1) != 0)
			{
				if (val.dy > 0)
				{
					if (val.dx >= val.dy)
					{
						val.e = val.dx;
						val.dx = val.dx * 2;
						val.dy = val.dy * 2;
						while (1)
						{
							fill_pixel(shape, val.x1 - *shape->min_x + 100,
							val.y1 + (shape->img_y - *shape->max_y - 100), col);
							if ((val.x1 = val.x1 + 1) == val.x2)
								break ;
							if ((val.e = val.e - val.dy) < 0)
							{
								val.y1++;
								val.e = val.e + val.dx;
							}
						}
					}
					else
					{
						val.e = val.dy;
						val.dy = val.dy * 2;
						val.dx = val.dx * 2;
						while (1)
						{
							fill_pixel(shape, val.x1 - *shape->min_x + 100,
							val.y1 + (shape->img_y - *shape->max_y - 100), col);
							if ((val.y1 = val.y1 + 1) == val.y2)
								break ;
							if ((val.e = val.e - val.dx) < 0)
							{
								val.x1++;
								val.e = val.e + val.dy;
							}
						}
					}
				}
				else
				{
					if (val.dx >= (-val.dy))
					{
						val.e = val.dx;
						val.dx = val.dx * 2;
						val.dy = val.dy * 2;
						while (1)
						{
							fill_pixel(shape, val.x1 - *shape->min_x + 100,
							val.y1 + (shape->img_y - *shape->max_y - 100), col);
							if ((val.x1 = val.x1 + 1) == val.x2)
								break ;
							if ((val.e = val.e + val.dy) < 0)
							{
								val.y1--;
								val.e = val.e + val.dx;
							}
						}
					}
					else
					{
						val.e = val.dy;
						val.dy = val.dy * 2;
						val.dx = val.dx * 2;
						while (1)
						{
							fill_pixel(shape, val.x1 - *shape->min_x + 100,
							val.y1 + (shape->img_y - *shape->max_y - 100), col);
							if ((val.y1 = val.y1 - 1) == val.y2)
								break ;
							if ((val.e = val.e + val.dx) > 0)
							{
								val.x1++;
								val.e = val.e + val.dy;
							}
						}
					}
				}
			}
			else
			{
				while (1)
				{
					fill_pixel(shape, val.x1 - *shape->min_x + 100,
					val.y1 + (shape->img_y - *shape->max_y - 100), col);
					if ((val.x1 = val.x1 + 1) == val.x2)
						break ;
				}
			}
		}
		else
		{
			if ((val.dy = val.y2 - val.y1) != 0)
			{
				if (val.dy > 0)
				{
					if ((-val.dx) >= val.dy)
					{
						val.e = val.dx;
						val.dx = val.dx * 2;
						val.dy = val.dy * 2;
						while (1)
						{
							fill_pixel(shape, val.x1 - *shape->min_x + 100,
							val.y1 + (shape->img_y - *shape->max_y - 100), col);
							if ((val.x1 = val.x1 - 1) == val.x2)
								break ;
							if ((val.e = val.e + val.dy) >= 0)
							{
								val.y1++;
								val.e = val.e + val.dx;
							}
						}
					}
					else
					{
						val.e = val.dy;
						val.dy = val.dy * 2;
						val.dx = val.dx * 2;
						while (1)
						{
							fill_pixel(shape, val.x1 - *shape->min_x + 100,
							val.y1 + (shape->img_y - *shape->max_y - 100), col);
							if ((val.y1 = val.y1 + 1) == val.y2)
								break ;
							if ((val.e = val.e + val.dx) <= 0)
							{
								val.x1--;
								val.e = val.e + val.dy;
							}
						}
					}
				}
				else
				{
					if (val.dx <= val.dy)
					{
						val.e = val.dx;
						val.dx = val.dx * 2;
						val.dy = val.dy * 2;
						while (1)
						{
							fill_pixel(shape, val.x1 - *shape->min_x + 100,
							val.y1 + (shape->img_y - *shape->max_y - 100), col);
							if ((val.x1 = val.x1 - 1) == val.x2)
								break ;
							if ((val.e = val.e - val.dy) >= 0)
							{
								val.y1--;
								val.e = val.e + val.dx;
							}
						}
					}
					else
					{
						val.e = val.dy;
						val.dy = val.dy * 2;
						val.dx = val.dx * 2;
						while (1)
						{
							fill_pixel(shape, val.x1 - *shape->min_x + 100,
							val.y1 + (shape->img_y - *shape->max_y - 100), col);
							if ((val.y1 = val.y1 - 1) == val.y2)
								break ;
							if ((val.e = val.e - val.dx) >= 0)
							{
								val.x1--;
								val.e = val.e + val.dy;
							}
						}
					}
				}
			}
			else
			{
				while (1)
				{
					fill_pixel(shape, val.x1 - *shape->min_x + 100,
					val.y1 + (shape->img_y - *shape->max_y - 100), col);
					if ((val.x1 = val.x1 - 1) == val.x2)
						break ;
				}
			}
		}
	}
	else
	{
		if ((val.dy = val.y2 - val.y1) != 0)
		{
			if (val.dy > 0)
			{
				while (1)
				{
					fill_pixel(shape, val.x1 - *shape->min_x + 100,
					val.y1 + (shape->img_y - *shape->max_y - 100), col);
					if ((val.y1 = val.y1 + 1) == val.y2)
						break ;
				}
			}
			else
			{
				while (1)
				{
					fill_pixel(shape, val.x1 - *shape->min_x + 100,
					val.y1 + (shape->img_y - *shape->max_y - 100), col);
					if ((val.y1 = val.y1 - 1) == val.y2)
						break ;
				}
			}
		}
	}
	fill_pixel(shape, val.x1 - *shape->min_x + 100,
	val.y1 + (shape->img_y - *shape->max_y - 100), col);
}

void		ft_draw_funct(t_shape *shape)
{
	t_slist		*current;
	t_slist		*current2;
	t_link		*ptr;
	int			color;

	current = shape->list;
	while (current)
	{
		current2 = current;
		while (current2)
		{
			ptr = (t_link *)current2->link;
			color = (ptr->color) ? ptr->color :
				ft_couleur(ptr->x * 10, ptr->y * 20, 200);
			if (current2->next_y)
				ft_draw_segment(shape, (t_link *)current2->link,
						(t_link *)current2->next_y->link, color);
			if (current2->next_x)
				ft_draw_segment(shape, (t_link *)current2->link,
						(t_link *)current2->next_x->link, color);
			current2 = current2->next_x;
		}
		current = current->next_y;
	}
}

void		ft_projection(t_shape *shape)
{
	t_slist		*current;
	t_slist		*current2;
	t_link		*ptr;

	current = shape->list;
	while (current)
	{
		current2 = current;
		while (current2)
		{
			ptr = (t_link *)current2->link;
			ptr->u = shape->agr * (((ptr->x)
						* cos(shape->coef_a + shape->coef_x)) + ((ptr->y)
						* cos(shape->coef_a + shape->coef_y)) + ((ptr->z)
						* cos(shape->coef_a - shape->coef_z)));
			ptr->v = shape->agr * (((ptr->x)
						* sin(shape->coef_a + shape->coef_x)) + ((ptr->y)
						* sin(shape->coef_a + shape->coef_y)) + ((ptr->z)
						* sin(shape->coef_a - shape->coef_z)));
			if (shape->first == 0)
			{
				if (!shape->max_y || *shape->max_y < ptr->v)
					*shape->max_y = ptr->v;
				if (!shape->max_x || *shape->max_x < ptr->u)
					*shape->max_x = ptr->u;
				if (!shape->min_y || *shape->min_y > ptr->v)
					*shape->min_y = ptr->v;
				if (!shape->min_x || *shape->min_x > ptr->u)
					*shape->min_x = ptr->u;
			}
			current2 = current2->next_x;
		}
		current = current->next_y;
	}
	shape->first = 1;
	ft_draw_funct(shape);
}

int			ft_key_funct(int key, t_shape *shape)
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
	if (key == 14)
		shape->coef_z += 1;
	if (key == 2)
		shape->coef_z -= 1;
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
	if (key == 36)
	{
		ft_putstr("		coef_x : ");
		ft_putnbr(shape->coef_x);
		ft_putchar('\n');
		ft_putstr("		coef_y : ");
		ft_putnbr(shape->coef_y);
		ft_putchar('\n');
		ft_putstr("		coef_z : ");
		ft_putnbr(shape->coef_z);
		ft_putchar('\n');
		ft_putstr("		coef_a : ");
		ft_putnbr(shape->coef_a);
		ft_putchar('\n');
	}
	if (key == 53)
		exit(1);
	mlx_clear_window(shape->mlx, shape->win);
	mlx_destroy_image(shape->mlx, shape->img);
	shape->img = mlx_new_image(shape->mlx, shape->img_x, shape->img_y);
	shape->data = mlx_get_data_addr(shape->img, &shape->bpp,
			&shape->sizeline, &shape->endian);
	ft_projection(shape);
	mlx_put_image_to_window(shape->mlx, shape->win, shape->img, 0, 0);
	return (0);
}

void		ft_draw(t_shape *shape)
{
	t_shape	*var;

	var = shape;
	var->mlx = mlx_init();
	var->win_x = 800;
	var->win_y = 800;
	var->img_x = var->win_x;
	var->img_y = var->win_y;
	shape->agr = 1;
	var->win = mlx_new_window(var->mlx, var->win_x, var->win_y, "test");
	var->img = mlx_new_image(var->mlx, var->img_x, var->img_y);
	var->data = mlx_get_data_addr(var->img, &var->bpp,
			&var->sizeline, &var->endian);
	var->coef_x = 31;
	var->coef_y = 13;
	var->coef_z = 33;
	var->coef_a = 0;
	ft_projection(var);
	mlx_put_image_to_window(var->mlx, var->win, var->img, 0, 0);
	mlx_key_hook(var->win, ft_key_funct, var);
	mlx_loop(var->mlx);
}
