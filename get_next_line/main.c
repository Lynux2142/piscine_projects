/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:16:24 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/12 12:10:31 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <unistd.h>
#include <fcntl.h>

#define NB 1

int		main(int ac, char **av)
{
	int		fd[NB];
	char	*line;
	int		result;
	int		i;

	(void)ac;
	i = 0;
	while (i < NB)
	{
		if ((fd[i] = open(av[1], O_RDONLY)) == -1)
			return (-1);
		++i;
	}
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
	i = 0;
	while (i < NB)
	{
		if (close(fd[0]))
			return (-1);
		++i;
	}
	return (0);
}
