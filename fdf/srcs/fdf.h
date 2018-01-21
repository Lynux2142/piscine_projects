/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 12:33:17 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/20 17:45:16 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct				s_shape
{
	struct s_slist			*list;
	void					*mlx;
	void					*win;
	void					*img;
	char					*data;
	int						bpp;
	int						sizeline;
	int						endian;
	int						win_x;
	int						win_y;
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

void						ft_check_stock(int fd, t_slist **list);
void						ft_clear_list(t_slist **list);
void						ft_print_list(t_slist *list);
t_slist						*ft_add_first_line(t_slist *current,
							char *line, int y);
t_slist						*ft_add_next_line(t_slist *current,
							t_slist *previous, char *line, int y);
void						ft_draw(t_slist **list);

#endif
