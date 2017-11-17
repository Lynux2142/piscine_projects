/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lstmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:51:15 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/17 11:48:12 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

#define D_ERROR { printf("Error Line %d, Funct %s\n", __LINE__ - 1, __func__); return (0); }

t_list	*uf_testmap(t_list *elem)
{
	t_list		*new;
	char		*content;
	size_t		i;

	content = ft_strdup((char *)(elem->content));
	i = 0;
	while (i < ft_strlen(content))
	{
		content[i] += 1;
		++i;
	}
	new = ft_lstnew((void const *) content, 5);
	free(content);
	return (new);
}

int		main(void)
{
	t_list	*lst_initial;
	t_list	*lst;
	char	*content;

	if (!(content = malloc(sizeof(char) * 4 + 1)))
		return (0);
	content = "toto";
	lst_initial = ft_lstnew((void const *) content, 5);
	content = "tata";
	lst_initial->next = ft_lstnew((void const *) content, 5);
	content = "tutu";
	lst_initial->next->next = ft_lstnew((void const *) content, 5);
	lst = ft_lstmap(lst_initial, &uf_testmap);
	printf("%s --- %s\n", lst_initial->content, lst->content);
	printf("%s --- %s\n", lst_initial->next->content, lst->next->content);
	printf("%s --- %s\n", lst_initial->next->next->content, lst->next->next->content);
	if (!strcmp((const char *) lst->content, (const char *) lst_initial->content) || strcmp((const char *) lst->content, "upup"))
		D_ERROR;
	if (!strcmp((const char *) lst->next->content, (const char *) lst_initial->next->content) || strcmp((const char *) lst->next->content, "ubub"))
		D_ERROR;
	if (!strcmp((const char *) lst->next->next->content, (const char *) lst_initial->next->next->content) || strcmp((const char *) lst->next->next->content, "uvuv"))
		D_ERROR;
	return (1);
}
