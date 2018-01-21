/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stock.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 15:52:41 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/19 15:31:22 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fdf.h"

void		ft_check_stock(int fd, t_slist **list)
{
	t_slist	*current;
	t_slist	*previous;
	char	*line;
	int		y;

	current = *list;
	get_next_line(fd, &line);
	previous = ft_add_first_line(current, line, 0);
	ft_memdel((void *)&line);
	y = 1;
	while (get_next_line(fd, &line) > 0)
	{
		if (!(current->next_y = (t_slist *)ft_memalloc(sizeof(t_slist))))
			return ;
		if (!(current->next_y->link = (t_link *)ft_memalloc(sizeof(t_link))))
			return ;
		current = current->next_y;
		previous = ft_add_next_line(current, previous, line, y);
		ft_memdel((void *)&line);
		++y;
	}
	ft_memdel((void *)&line);
}
