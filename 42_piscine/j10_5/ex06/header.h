/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 08:35:25 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/25 13:47:50 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>

int		ft_atoi(char *str);
void	ft_plus(int frst, int scnd);
void	ft_minus(int frst, int scnd);
void	ft_multiply(int frst, int scnd);
void	ft_divide(int frst, int scnd);
void	ft_modulo(int frst, int scnd);
void	ft_print_result(int result);

#endif
