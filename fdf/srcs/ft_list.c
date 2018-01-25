/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:12:23 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/25 14:17:04 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fdf.h"
#include <stdlib.h>

static void		ft_clear_tmp(char **tmp)
{
	int i;

	i = -1;
	while (tmp[++i])
		ft_memdel((void *)&tmp[i]);
	ft_memdel((void **)&tmp);
}

static void		ft_register(t_shape *shape, int x, int y, char *z_col)
{
	t_link	*data;
	char	**tmp;

	data = ((t_link *)shape->temp->link);
	tmp = ft_strsplit(z_col, ',');
	data->x = x;
	data->y = y;
	data->z = ft_atoi(tmp[0]);
	if (tmp[1] != NULL)
		data->color = ft_atoi_base(tmp[1], 16);
	ft_clear_tmp(tmp);
}

void			ft_clear_list(t_slist **list)
{
	t_slist	*current;
	t_slist	*next_line;
	t_slist	*tmp;

	next_line = *list;
	while (next_line)
	{
		current = next_line;
		next_line = next_line->next_y;
		while (current)
		{
			tmp = current;
			current = current->next_x;
			ft_memdel((void **)&tmp->link);
			ft_memdel((void **)&tmp);
		}
	}
}

t_slist			*ft_add_first_line(t_shape *shape, char *line, int y)
{
	char		**tmp;

	shape->temp = ((t_slist *)shape->current);
	tmp = ft_strsplit(line, ' ');
	shape->width = 0;
	ft_register(shape, shape->width, y, tmp[shape->width]);
	while (tmp[++shape->width])
	{
		if (!(shape->temp->next_x = (t_slist *)ft_memalloc(sizeof(t_slist)))
		|| !(shape->temp->next_x->link = (t_link *)ft_memalloc(sizeof(t_link))))
			return (NULL);
		shape->temp = ((t_slist *)shape->temp)->next_x;
		ft_register(shape, shape->width, y, tmp[shape->width]);
	}
	ft_clear_tmp(tmp);
	return ((t_slist *)shape->list);
}

t_slist			*ft_add_next_line(t_shape *shape, char *line, int y)
{
	int			x;
	char		**tmp;

	shape->temp = ((t_slist *)shape->current);
	tmp = ft_strsplit(line, ' ');
	x = 0;
	ft_register(shape, x, y, tmp[x]);
	while (tmp[++x])
	{
		if (!(shape->temp->next_x = (t_slist *)ft_memalloc(sizeof(t_slist)))
		|| !(shape->temp->next_x->link = (t_link *)ft_memalloc(sizeof(t_link))))
			return (NULL);
		shape->previous->next_y = ((t_slist *)shape->temp);
		shape->temp = ((t_slist *)shape->temp)->next_x;
		shape->previous = ((t_slist *)shape->previous)->next_x;
		ft_register(shape, x, y, tmp[x]);
	}
	if (x != shape->width)
	{
		ft_putendl("Found wrong line length. Exiting.");
		exit(-1);
	}
	shape->previous->next_y = ((t_slist *)shape->temp);
	ft_clear_tmp(tmp);
	return ((t_slist *)shape->current);
}
