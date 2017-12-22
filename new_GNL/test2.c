/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 10:13:07 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/22 10:23:49 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>



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
		ft_putendl(line);
		ft_memdel((void *)&line);
		--nb;
	}
	return (0);
}
