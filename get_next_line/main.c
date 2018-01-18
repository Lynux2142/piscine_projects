/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 09:48:14 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/18 10:02:05 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

/*
** #include "get_next_line.h"
*/

#include <unistd.h>
#include <fcntl.h>

#define NB 1

static void	close_fd(int *fd)
{
	int i;

	i = -1;
	while (++i < NB)
		close(fd[i]);
}

static void	open_file(int *fd, char *file)
{
	int i;

	i = -1;
	while (++i < NB)
		fd[i] = open(file, O_RDONLY);
}

int			main(int ac, char **av)
{
	int		fd[NB];
	char	*line;
	int		result;
	int		i;

	(void)ac;
	open_file(fd, av[1]);
	i = 0;
	while ((result = get_next_line((const int)fd[i], &line)) > 0)
	{
		ft_putendl(line);
		ft_memdel((void *)&line);
		++i;
		if (i == NB)
			i = 0;
	}
	ft_memdel((void *)&line);
	close_fd(fd);
	return (0);
}
