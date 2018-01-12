/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:24:31 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/12 14:50:16 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

/*
** #include "get_next_line.h"
*/

#include <unistd.h>
#include <stdlib.h>

static t_list	*ft_check(t_list **list, size_t fd)
{
	t_list	*current;
	t_list	*elem;

	current = *list;
	while (current)
	{
		if (current->content_size == fd)
			return (current);
		current = current->next;
	}
	if (!(elem = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (!(elem->content = ft_memalloc(sizeof(t_struct))))
		return (NULL);
	elem->content_size = fd;
	ft_lstadd(list, elem);
	return (elem);
}

static char		ft_getchar(const int fd, int *rd_len, t_struct *var)
{
	char		c;

	if (var->len == 0)
	{
		if ((*rd_len = read(fd, var->buff, BUFF_SIZE)) <= 0)
			return ((*rd_len == 0) ? 0 : -1);
		var->len = *rd_len;
		var->str = (char *)&var->buff;
	}
	c = *var->str;
	++var->str;
	--var->len;
	return (c);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*link;
	char			c;
	int				len;

	if (line == NULL || fd < 0 || !BUFF_SIZE || !(*line = ft_strnew(BUFF_SIZE)))
		return (-1);
	link = (t_list *)ft_check(&list, (size_t)fd);
	c = ft_getchar(link->content_size,
		&(((t_struct *)link->content)->rd_len), (t_struct *)link->content);
	if (((t_struct *)link->content)->rd_len < 0)
		return (-1);
	len = 0;
	while (c != GNL_CAR && (((t_struct *)link->content))->rd_len > 0)
	{
		line[0][len] = c;
		c = ft_getchar(link->content_size,
			&(((t_struct *)link->content)->rd_len), (t_struct *)link->content);
		++len;
		if ((len % BUFF_SIZE) == 0)
			*line = ft_realloc(*line, len + BUFF_SIZE + 1);
	}
	line[0][len] = '\0';
	return ((**line == '\0' && c != GNL_CAR) ? 0 : 1);
}