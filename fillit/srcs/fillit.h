/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:34:46 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/01 12:18:15 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef int		t_bool;

char			*ft_stock_and_check_file(char *file);

t_list			*ft_split_rec_tetri(char *tab);

int				ft_nb_tetri(char *tab);
int				ft_nb_row(char *tab);
int				ft_sqrt(int nb);

t_list			*ft_solve_grid(t_list *tetris, char **grid, int g_len);

void			ft_list_push_back(t_list **list, int *content, size_t c_size);
int				ft_listlen(t_list *list);
t_list			*ft_create_elem(int *content, size_t c_size);
void			ft_print_list_content(t_list *list, size_t c_size);

void			ft_print_result(char **grid, int len);
char			**ft_create_square(int len);

#endif
