/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 16:08:29 by lguiller          #+#    #+#             */
/*   Updated: 2018/03/14 17:59:18 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

static void	ft_write_data(t_shape *shape, char *data, int fd)
{
	int max;
	int x;
	int i;

	max = (shape->img_y * shape->sizeline);
	x = 0;
	i = 0;
	while ((x += 4) < max)
	{
		i += 4;
		if (i >= shape->sizeline)
		{
			ft_putchar_fd('\n', fd);
			i = 0;
		}
		else
		{
			ft_putnbr_fd(255 - (int)((unsigned char)data[x]) * 100 / 255, fd);
			ft_putchar_fd(' ', fd);
		}
	}
}

void		ft_create_fdf(t_shape *shape, char *data)
{
	int		fd;

	(void)data;
	if ((fd = open("fract.fdf", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR)) == -1)
	{
		perror("error");
		exit(5);
	}
	ft_write_data(shape, data, fd);
	if ((close(fd) == -1))
	{
		perror("error");
		exit(6);
	}
}
