/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:16:24 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/22 16:17:35 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	int		len;
	int		fd;
	char	*line;

	(void)ac;
	len = ft_atoi(av[2]);
	fd = open(av[1], O_RDONLY);
	while (len > 0)
	{
		get_next_line(fd, &line);
		ft_putendl(line);
		ft_memdel((void *)&line);
		--len;
	}
	close(fd);
	return (0);
}
