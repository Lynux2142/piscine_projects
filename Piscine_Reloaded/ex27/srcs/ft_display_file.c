/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:59:02 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/10 11:37:50 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	int		fd;
	char	buf;
	long	rd;

	if (ac != 2)
	{
		if (ac > 2)
			write(2, "Too many arguments.\n", 20);
		if (ac < 2)
			write(2, "File name missing.\n", 19);
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (1);
	rd = read(fd, &buf, 1);
	while (rd != 0)
	{
		write(1, &buf, rd);
		rd = read(fd, &buf, 1);
	}
	close(fd);
	return (0);
}
