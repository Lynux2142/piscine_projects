/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:17:10 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/12 09:39:50 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int		main(int ac, char **av)
{
	int		i;
	int		fd;
	char	*line;

	line = NULL;
	if (ac != 2)
		return (-1);
	if (!(fd = open(av[1], O_RDONLY)))
		return (2);
	get_next_line(fd, &line);
	ft_putendl(line);
	i = -1;
	while (line[++i])
		ft_memdel((void *)&(line[i]));
	ft_memdel((void **)&line);
	close(fd);
	return (1);
}
