/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 11:27:27 by lguiller          #+#    #+#             */
/*   Updated: 2018/02/20 11:08:57 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <mlx.h>
# include <stdlib.h>

typedef struct		s_draw
{
	int				x;
	int				y;
	double			image_x;
	double			image_y;
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
}					t_shape;

typedef void		(*t_funct)(t_shape*);

void				ft_usage(void);
void				ft_clear(t_shape *shape);
void				ft_display(t_shape *shape);
int					ft_key_funct(int key, t_shape *shape);
int					ft_mouse_funct(int mouse, int x, int y, t_shape *shape);
t_funct				get_f_funct(char *name_f);
void				apply_zoom(t_shape *shape, double mouse_re,
					double mouse_im, double zoom_factor);
void				ft_init(t_shape *shape, t_draw *draw);
double				ft_pow(double nb, int power);
void				fill_pixel(t_shape *shape, int x, int y, int color);
int					ft_couleur(int red, int green, int blue);
void				fract1(t_shape *shape);
void				fract2(t_shape *shape);
void				fract3(t_shape *shape);
void				ft_set_values(t_shape *shape);
int					ft_var_julia(int x, int y, t_shape *shape);

#endif
