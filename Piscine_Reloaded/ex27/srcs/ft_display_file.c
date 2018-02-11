/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:59:02 by lguiller          #+#    #+#             */
/*   Updated: 2018/02/11 12:43:07 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int		main(int ac, char **av)
{
	int		fd;
	char	buf;
	long	rd;

	if (ac != 2)
	{
		if (ac > 2)
			ft_putstr_fd(2, "Too many arguments.\n");
		if (ac < 2)
			ft_putstr_fd(2, "File name missing.\n");
		return (1);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (2);
	while ((rd = read(fd, &buf, 1)) != 0)
		write(1, &buf, rd);
	if (close(fd) == -1)
		return (3);
	return (0);
}
