/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:47:21 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/25 16:20:06 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fdf.h"
#include <fcntl.h>
#include <unistd.h>

void		ft_print_list(t_slist *list)
{
	t_slist		*line;
	char		*nbr;

	while (list)
	{
		line = list;
		while (line)
		{
			ft_putnbr(((t_link *)line->link)->z);
			if (((t_link *)line->link)->color)
			{
				ft_putstr(",0x");
				nbr = ft_itoa_base(((t_link *)line->link)->color, 16);
				ft_putstr(nbr);
				ft_memdel((void *)&nbr);
			}
			if (line->next_x != NULL)
				ft_putchar(' ');
			line = line->next_x;
		}
		ft_putchar('\n');
		list = list->next_y;
	}
}

int			main(int ac, char **av)
{
	t_shape	shape;
	int		fd;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) <= 0)
			return (-1);
		if (!(shape.list = (t_slist *)ft_memalloc(sizeof(t_slist))))
			return (-1);
		if (!(((t_slist *)shape.list)->link =
		(t_link *)ft_memalloc(sizeof(t_link))))
			return (-1);
		((t_link *)((t_slist *)shape.list)->link)->x = 0;
		((t_link *)((t_slist *)shape.list)->link)->y = 0;
		ft_check_stock(fd, &shape);
		ft_draw(&shape);
		ft_clear_list(&shape.list);
		if (!close(fd))
			return (-1);
	}
	else
		ft_putendl_fd("usage: ./fdf [file_name.fdf]", 2);
	return (0);
}
