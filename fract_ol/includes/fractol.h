/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 11:27:27 by lguiller          #+#    #+#             */
/*   Updated: 2018/02/09 13:20:23 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <mlx.h>
# include <stdlib.h>

typedef struct		s_basic
{
	double			x1;
	double			x2;
	double			y1;
	double			y2;
}					t_basic;

typedef struct		s_shape
{
	t_basic			basic;
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
}					t_shape;

typedef struct		s_fract
{
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			i;
}					t_fract;

typedef void		(*t_funct)(t_shape*);

#endif
