/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 12:33:17 by lguiller          #+#    #+#             */
/*   Updated: 2018/02/21 09:16:30 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

typedef struct				s_shape
{
	int						first;
	struct s_slist			*list;
	struct s_slist			*end_list;
	struct s_slist			*previous;
	struct s_slist			*current;
	struct s_slist			*temp;
	struct s_slist			*prev_y;
	struct s_slist			*prev_x;
	void					*mlx;
	void					*win;
	void					*img;
	char					*data;
	int						bpp;
	int						sizeline;
	int						endian;
	int						*min_y;
	int						*max_y;
	int						*min_x;
	int						*max_x;
	double					agr;
	int						width;
	int						win_x;
	int						win_y;
	int						img_x;
	int						img_y;
	double					coef_x;
	double					coef_y;
	double					coef_z;
	double					coef_a;
	double					rot;
	int						start_x;
	int						start_y;
	int						speed;
	int						x_max;
	int						y_max;
	char					**tmp;
	int						line_len;
	char					ok;
}							t_shape;

typedef struct				s_slist
{
	struct s_slist			*next_x;
	struct s_slist			*next_y;
	struct s_slist			*prev_x;
	struct s_slist			*prev_y;
	struct s_link			*link;
}							t_slist;

typedef struct				s_link
{
	int						x;
	int						y;
	int						z;
	int						color;
	double					u;
	double					v;
}							t_link;

typedef struct				s_draw
{
	int						x1;
	int						y1;
	int						x2;
	int						y2;
	int						dy;
	int						dx;
	int						e;
}							t_draw;

void						ft_error(char *str);
void						ft_check_stock(int fd, t_shape *shape);
void						ft_clear_list(t_slist **list);
t_slist						*ft_add_first_line(t_shape *shape,
								char *line, int y);
t_slist						*ft_add_next_line(t_shape *shape,
								char *line, int y);
void						ft_draw(t_shape *shape);
int							ft_couleur(int red, int green, int blue);
void						ft_projection(t_shape *shape);
int							ft_mouse_funct(int mouse, int x, int y,
								t_shape *shape);
int							ft_key_funct(int key, t_shape *shape);
int							ft_couleur(int red, int green, int blue);
void						fill_pixel(t_shape *shape, int x, int y, int color);
void						projection_calcul(t_shape *shape, t_link *ptr);
int							ft_calcul_color(t_slist *first, t_slist *second);
void						ft_draw_segment(t_shape *shape,
								t_link *xy1, t_link *xy2, int col);
void						draw_octan_one(t_shape *shape,
								t_draw *val, int col);
void						draw_octan_two(t_shape *shape,
								t_draw *val, int col);
void						draw_octan_three(t_shape *shape,
								t_draw *val, int col);
void						draw_octan_four(t_shape *shape,
								t_draw *val, int col);
void						draw_octan_five(t_shape *shape,
								t_draw *val, int col);
void						draw_octan_six(t_shape *shape,
								t_draw *val, int col);
void						draw_octan_seven(t_shape *shape,
								t_draw *val, int col);
void						draw_octan_eight(t_shape *shape,
								t_draw *val, int col);
void						draw_horizontal_right(t_shape *shape,
								t_draw *val, int col);
void						draw_horizontal_left(t_shape *shape,
								t_draw *val, int col);
void						draw_vertical_increasing(t_shape *shape,
								t_draw *val, int col);
void						draw_vertical_decreasing(t_shape *shape,
								t_draw *val, int col);
void						ft_clear_tmp(char **tmp);
int							ft_rotate_auto(t_shape *shape);
void						choose_color(t_shape *shape, t_slist *list);

#endif
