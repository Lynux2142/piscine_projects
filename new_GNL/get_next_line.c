/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 11:17:52 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/21 17:34:07 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

#define BUFF_SIZE 3

int		get_next_line(const int fd, char **line)
{
	static char	*buff;
	char		*tmp;
	int			curs;
	int			i;

	buff = ft_strnew(BUFF_SIZE);
	ft_bzero(buff, BUFF_SIZE);
	tmp = ft_strnew(BUFF_SIZE);
	*line = ft_strnew(BUFF_SIZE);
	if (read(fd, buff, BUFF_SIZE) == -1 || read(fd, buff, BUFF_SIZE) == 0)
		return (read(fd, buff, BUFF_SIZE));
	while (read(fd, buff, BUFF_SIZE))
	{
		curs = 0;
		i = ft_strlen(*line);
		ft_bzero(tmp, BUFF_SIZE);
		while (*buff && *buff != '\n')
		{
			tmp[i] = *buff + curs;
			++i;
			++curs;
		}
		*line = ft_strjoin(tmp, buff);
		if (*buff == '\n' && *(buff + 1) != '\0')
			buff = ft_strchr(buff, '\n');
	}
	return (1);
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
		ft_putnbr(get_next_line(fd, &line));
		ft_putchar('\n');
		get_next_line(fd, &line);
		ft_putendl(line);
		ft_memdel((void *)line);
		--nb;
	}
	return (0);
}
