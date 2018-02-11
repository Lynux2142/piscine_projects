/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:08:03 by lguiller          #+#    #+#             */
/*   Updated: 2018/02/11 12:43:02 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIB_H
# define MYLIB_H

# include <unistd.h>
#include <fcntl.h>

void	ft_putstr_fd(int fd, char *str);
int		ft_strlen(char *str);

#endif
