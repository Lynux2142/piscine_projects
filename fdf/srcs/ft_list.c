/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:12:23 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/20 17:26:16 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fdf.h"

static void		ft_clear_tmp(char **tmp)
{
	int i;

	i = -1;
	while (tmp[++i])
		ft_memdel((void *)&tmp[i]);
	ft_memdel((void **)&tmp);
}

static void		ft_register(t_link *data, int x, int y, char *z_col)
{
	char	**tmp;

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

t_slist			*ft_add_first_line(t_slist *current, char *line, int y)
{
	t_slist		*temp;
	int			x;
	char		**tmp;

	temp = current;
	tmp = ft_strsplit(line, ' ');
	x = 0;
	ft_register(((t_link *)temp->link), x, y, tmp[x]);
	while (tmp[++x])
	{
		if (!(temp->next_x = (t_slist *)ft_memalloc(sizeof(t_slist)))
		|| !(temp->next_x->link = (t_link *)ft_memalloc(sizeof(t_link))))
			return (NULL);
		temp = temp->next_x;
		ft_register(((t_link *)temp->link), x, y, tmp[x]);
	}
	ft_clear_tmp(tmp);
	return (current);
}

t_slist			*ft_add_next_line(t_slist *current,
		t_slist *previous, char *line, int y)
{
	t_slist		*temp;
	int			x;
	char		**tmp;

	temp = current;
	tmp = ft_strsplit(line, ' ');
	x = 0;
	ft_register(((t_link *)temp->link), x, y, tmp[x]);
	while (tmp[++x])
	{
		if (!(temp->next_x = (t_slist *)ft_memalloc(sizeof(t_slist)))
		|| !(temp->next_x->link = (t_link *)ft_memalloc(sizeof(t_link))))
			return (NULL);
		previous->next_y = temp;
		temp = temp->next_x;
		previous = previous->next_x;
		ft_register(((t_link *)temp->link), x, y, tmp[x]);
	}
	previous->next_y = temp;
	ft_clear_tmp(tmp);
	return (current);
}
