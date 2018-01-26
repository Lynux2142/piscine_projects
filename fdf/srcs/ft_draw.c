/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 10:04:09 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/26 17:07:21 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
							val.y1 + (shape->img_y / 2 - *shape->max_y), col);
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
							val.y1 + (shape->img_y / 2 - *shape->max_y), col);
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
							val.y1 + (shape->img_y / 2 - *shape->max_y), col);
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
							val.y1 + (shape->img_y / 2 - *shape->max_y), col);
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
					val.y1 + (shape->img_y / 2 - *shape->max_y), col);
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
							val.y1 + (shape->img_y / 2 - *shape->max_y), col);
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
							val.y1 + (shape->img_y / 2 - *shape->max_y), col);
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
							val.y1 + (shape->img_y / 2 - *shape->max_y), col);
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
							val.y1 + (shape->img_y / 2 - *shape->max_y), col);
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
					val.y1 + (shape->img_y / 2 - *shape->max_y), col);
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
					val.y1 + (shape->img_y / 2 - *shape->max_y), col);
					if ((val.y1 = val.y1 + 1) == val.y2)
						break ;
				}
			}
			else
			{
				while (1)
				{
					fill_pixel(shape, val.x1 - *shape->min_x + 100,
					val.y1 + (shape->img_y / 2 - *shape->max_y), col);
					if ((val.y1 = val.y1 - 1) == val.y2)
						break ;
				}
			}
		}
	}
	fill_pixel(shape, val.x1 - *shape->min_x + 100,
	val.y1 + (shape->img_y / 2 - *shape->max_y), col);
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

void		ft_xtrem_values(t_shape *shape, t_link *ptr)
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
			projection_calcul_u(shape, ptr);
			projection_calcul_v(shape, ptr);
			if (shape->first == 0)
				ft_xtrem_values(shape, ptr);
			current2 = current2->next_x;
		}
		current = current->next_y;
	}
	shape->first = 1;
	ft_draw_funct(shape);
}

void		ft_draw(t_shape *shape)
{
	shape->mlx = mlx_init();
	shape->win_x = 1200;
	shape->win_y = 1200;
	shape->img_x = shape->win_x;
	shape->img_y = shape->win_y;
	shape->agr = 1;
	shape->win = mlx_new_window(shape->mlx, shape->win_x, shape->win_y, "test");
	shape->img = mlx_new_image(shape->mlx, shape->img_x, shape->img_y);
	shape->data = mlx_get_data_addr(shape->img, &shape->bpp,
			&shape->sizeline, &shape->endian);
	shape->coef_x = 31;
	shape->coef_y = 13;
	shape->coef_z = 33;
	shape->coef_a = 0;
	ft_projection(shape);
	mlx_put_image_to_window(shape->mlx, shape->win, shape->img, 0, 0);
	mlx_key_hook(shape->win, ft_key_funct, shape);
	mlx_mouse_hook(shape->win, ft_mouse_funct, shape);
	mlx_loop(shape->mlx);
}
