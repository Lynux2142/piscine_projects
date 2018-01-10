/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:16:24 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/10 17:30:43 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		result;

	(void)ac;
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (-1);
	while ((result = get_next_line((const int)fd, &line)))
	{
		ft_putendl(line);
		ft_memdel((void *)&line);
	}
	ft_memdel((void *)&line);
	close(fd);
	return (0);
}
