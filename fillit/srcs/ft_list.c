/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 07:56:44 by manki             #+#    #+#             */
/*   Updated: 2017/12/01 13:01:29 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	ft_list_push_back(t_list **list, int *content, size_t c_size)
{
	t_list		*current;

	current = *list;
	if (list)
	{
		while (ft_listlen(current) > 1)
			current = current->next;
		current->next = ft_create_elem(content, c_size);
	}
}

int		ft_listlen(t_list *list)
{
	int		i;
	t_list	*current;

	i = 1;
	current = list;
	while ((current = current->next))
		i++;
	return (i);
}

void		ft_print_list_content(t_list *list, size_t c_size)
{
	t_list	*current;
	size_t	i;
	int		*id;

	if (!(current = (t_list *)ft_memalloc(sizeof(t_list))))
		return ;
	current = list;
	if (current)
	{
		while (current)
		{
			id = current->content;
			i = -1;
			while (++i < c_size)
				ft_putnbr(id[i]);
			ft_putchar('\n');
			current = current->next;
			id = NULL;
		}
	}
}

t_list		*ft_create_elem(int *content, size_t c_size)
{
	t_list	*current;
	void	*c_copy;

	if (!(current = (t_list *)ft_memalloc(sizeof(t_list))))
		return (NULL);
	if (current)
	{
		c_copy = content;
		current->content = c_copy;
		current->content_size = c_size;
		current->next = NULL;
	}
	return (current);
}
