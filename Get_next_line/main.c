/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:17:10 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/13 11:07:43 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int		main(int ac, char **av)
{
	int		fd;
	char	*line;

	line = NULL;
	if (ac != 2)
		return (-1);
	if (!(fd = open(av[1], O_RDONLY)))
		return (2);
	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putendl(line);
	free(line);
	close(fd);
	return (1);
}
