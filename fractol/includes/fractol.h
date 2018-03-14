/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 11:27:27 by lguiller          #+#    #+#             */
/*   Updated: 2018/03/14 12:51:25 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <math.h>

typedef struct		s_string
{
	int				mand;
	int				julia;
	int				burn;
}					t_string;

typedef struct		s_rect
{
	int				pos_x;
	int				pos_y;
	int				dim_x;
	int				dim_y;
	int				col;
}					t_rect;

typedef struct		s_draw
{
	int				x;
	int				y;
	double			tmp;
}					t_draw;

typedef struct		s_fract
{
	t_draw			draw;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			i;
}					t_fract;

typedef struct		s_shape
{
	char			*fract_name;
	void			*mlx;
	void			*win;
	void			*img;
	int				bpp;
	int				sizeline;
	int				endian;
	char			*data;
	int				win_x;
	int				win_y;
	int				img_x;
	int				img_y;
	double			iter;
	double			zoom;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			c_r;
	double			c_i;
	int				in_out;
	int				color;
	t_string		string;
}					t_shape;

typedef void		(*t_funct)(t_shape*);

void				ft_usage(void);
void				ft_display(t_shape *shape);
int					ft_key_funct(int key, t_shape *shape);
int					ft_mouse_funct(int mouse, int x, int y, t_shape *shape);
t_funct				get_f_funct(char *name_f);
void				apply_zoom(t_shape *shape, int x, int y,
						double zoom_factor);
void				ft_init(t_shape *shape, t_draw *draw);
void				fill_pixel(t_shape *shape, int x, int y, int color);
int					ft_couleur(int red, int green, int blue);
void				fract1(t_shape *shape);
void				fract2(t_shape *shape);
void				fract3(t_shape *shape);
void				ft_set_values(t_shape *shape);
int					ft_var_julia(int x, int y, t_shape *shape);
void				ft_set_color(t_shape *shape, t_fract f);
void				ft_set_string(t_shape *shape);

#endif
