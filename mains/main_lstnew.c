/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:15:16 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/17 09:59:21 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_print_result(char const *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

void	ft_print_result2(int n)
{
	char c;

	if (n >= 10)
		ft_print_result2(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}

int		main(int argc, const char *argv[])
{
	t_list		*elem;
	int			arg;

	alarm(5);
	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		char	str [] = "lorem ipsum dolor sit";

		if (!(elem = ft_lstnew(str, (sizeof(str)))))
			ft_print_result("NULL");
		else
		{
			if (!(elem->content))
				ft_print_result("NULL");
			else
			{
				ft_print_result(elem->content);
				write(1, "\n", 1);
			}
			ft_print_result2(elem->content_size);
			if (!(elem->next))
			{
				write(1, "\n", 1);
				ft_print_result("NULL");
			}
		}
	}
	else if (arg == 2)
	{
		int	i;

		i = 42;
		if (!(elem = ft_lstnew(&i, (sizeof(i)))))
			ft_print_result("NULL");
		else
		{
			if (!(elem->content))
				ft_print_result("NULL");
			else
			{
				ft_print_result2(*(int *)(elem->content));
				write(1, "\n", 1);
			}
			ft_print_result2(elem->content_size);
			if (!(elem->next))
			{
				write(1, "\n", 1);
				ft_print_result("NULL");
			}
		}
	}
	else if (arg == 3)
	{
		if (!(elem = ft_lstnew(NULL, 5)))
			ft_print_result("NULL");
		else
		{
			if (!(elem->content))
			{
				ft_print_result("NULL");
				write(1, "\n", 1);
			}
			else
			{
				ft_print_result(elem->content);
				write(1, "\n", 1);
			}
			ft_print_result2(elem->content_size);
			if (!(elem->next))
			{
				write(1, "\n", 1);
				ft_print_result("NULL");
			}
		}
	}
	else if (arg == 4)
	{
		char *data = "hello, i'm a data";

		t_list	*l = ft_lstnew(data, ft_strlen(data) + 1);
		if (!(l = ft_lstnew(data, sizeof(data + 1))))
			ft_print_result("NULL");
		if (!(l->content))
		{
			ft_print_result("NULL");
			write(1, "\n", 1);
		}
		else
		{
			ft_print_result(l->content);
			write(1, "\n", 1);
		}
		ft_print_result2(l->content_size);
		if (!(l->next))
		{
			write(1, "\n", 1);
			ft_print_result("NULL");
		}

	}
	return (0);
}
