/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_brackets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:48:23 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/12 16:48:40 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

void	ft_point(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '(' && str[i] != '{' && str[i] != '['
		&& str[i] != ')' && str[i] != '}' && str[i] != ']' && str[i] != '\0')
			str[i] = '.';
		++i;
	}
}

void	ft_cut(char *str)
{
	int	i;
	int	j;
	int	tmp;

	j = 0;
	i = 0;
	while (str[i])
	{
		j = i;
		tmp = i;
		while (str[j] == '.')
			++j;
		while (str[j])
		{
			str[tmp] = str[j];
			++tmp;
			++j;
		}
		while (str[tmp])
		{
			str[tmp] = '\0';
			++tmp;
		}
		++i;
	}
}

int		ft_check(char *str)
{
	int	secu;
	int	i;

	secu = ft_strlen(str);
	while (secu > 0)
	{
		i = 0;
		while (str[i])
		{
			if ((str[i] == '(' && str[i + 1] == ')')
					|| (str[i] == '{' && str[i + 1] == '}')
					|| (str[i] == '[' && str[i + 1] == ']'))
			{
				str[i] = '.';
				str[i + 1] = '.';
				ft_cut(str);
			}
			++i;
		}
		--secu;
	}
	return (1);
}

int		ft_brackets(char *str)
{
	ft_point(str);
	ft_cut(str);
	ft_check(str);
	if (str[0] != '\0')
		return (0);
	else
		return (1);
}
