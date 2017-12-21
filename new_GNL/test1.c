/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 15:47:32 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/21 16:57:01 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 1

int		get_next_line(const int fd, char **line)
{
	static char *buff;
	int			value;

	buff = ft_strnew(BUFF_SIZE / BUFF_SIZE);
	*line = ft_strnew(BUFF_SIZE / BUFF_SIZE);
	ft_bzero(*line, BUFF_SIZE / BUFF_SIZE);
	while ((value = read(fd, buff, BUFF_SIZE / BUFF_SIZE)))
	{
		if (value == -1 || value == 0)
			return (value);
		if (*buff == '\n')
		{
			ft_memdel((void *)&buff);
			return (1);
		}
		*line = ft_strjoin(*line, buff);
		ft_bzero(buff, BUFF_SIZE / BUFF_SIZE);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		nb;

	(void)ac;
	nb = ft_atoi(av[2]);
	fd = open(av[1], O_RDONLY);
	while (nb > 0)
	{
		get_next_line(fd, &line);
		--nb;
	}
	ft_putendl(line);
	ft_memdel((void *)&line);
	return (0);
}
