/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 12:33:17 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/22 17:16:40 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct				s_shape
{
	struct s_slist			*list;
	struct s_slist			*current;
	struct s_slist			*previous;
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
	int						max_l;
	int						max_w;
	int						*max_h;
	int						*min_h;
	int						win_x;
	int						win_y;
	int						img_x;
	int						img_y;
	int						coef_x;
	int						coef_y;
	int						coef_z;
	int						coef_a;
}							t_shape;

typedef struct				s_slist
{
	struct s_slist			*next_x;
	struct s_slist			*next_y;
	struct s_link			*link;
}							t_slist;

typedef struct				s_link
{
	int						x;
	int						y;
	int						z;
	int						color;
	int						u;
	int						v;
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

void						ft_check_stock(int fd, t_shape *shape);
void						ft_clear_list(t_slist **list);
void						ft_print_list(t_slist *list);
t_slist						*ft_add_first_line(t_shape *shape,
								char *line, int y);
t_slist						*ft_add_next_line(t_shape *shape,
								char *line, int y);
void						ft_draw(t_shape *shape);
int							ft_couleur(int red, int green, int blue);

#endif
