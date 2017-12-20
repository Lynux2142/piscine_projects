/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 14:27:27 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/20 16:15:23 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

int			main(void)
{
	char	*s1 = "bo";
	char	*s2 = "nj";
	char	*s3 = "ou";
	char	*s4 = "r";
	t_list	*lst;
	t_list	*curs;
	t_list	*tmp;

	lst = NULL;
	lst = lst_add_end(lst, s1, ft_strlen(s1));
	lst = lst_add_end(lst, s2, ft_strlen(s2));
	lst = lst_add_end(lst, s3, ft_strlen(s3));
	lst = lst_add_end(lst, s4, ft_strlen(s3));
	curs = lst;
	while (curs)
	{
		printf("%s", curs->content);
		curs = curs->next;
	}
	printf("\n");
	curs = lst;
	while (curs)
	{
		tmp = curs;
		curs = curs->next;
		ft_memdel((void *)&tmp);
	}
	return (0);
}
