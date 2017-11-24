/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:34:46 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/24 10:24:30 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

char		*ft_stock_file(char *file);
int			ft_check_norme(char *tab);
int			**ft_register_tetri(char *tab, char **group);
char		**ft_split_tetri(char *tab);
int			ft_nb_tetri(char *tab);
int			ft_nb_row(char *tab);
int			ft_sr(int nb);

#endif
