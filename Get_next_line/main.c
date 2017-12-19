/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:17:10 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/19 14:45:26 by lguiller         ###   ########.fr       */
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
	int		nb;

	nb = ft_atoi(av[2]);
	line = NULL;
	if (ac != 3)
		return (-1);
	if (!(fd = open(av[1], O_RDONLY)))
		return (2);
	while (nb > 0)
	{
		get_next_line(fd, &line);
		ft_putendl(line);
		ft_memdel((void *)&line);
		--nb;
	}
	close(fd);
	return (1);
}
