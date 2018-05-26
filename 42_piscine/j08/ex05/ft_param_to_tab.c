/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 18:19:21 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/22 19:11:34 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char				*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i] != 0)
		++i;
	if (!(dest = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	int				i;
	t_stock_par		*declar;

	if (!(declar = (t_stock_par*)malloc(sizeof(t_stock_par) * (ac + 1))))
		declar = NULL;
	i = 0;
	while (av[i] != '\0')
	{
		declar[i].size_param = ft_strlen(av[i]);
		declar[i].str = av[i];
		declar[i].copy = ft_strdup(av[i]);
		declar[i].tab = ft_split_whitespaces(av[i]);
		++i;
	}
	declar[i].str = 0;
	return (declar);
}
