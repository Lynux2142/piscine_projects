/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 13:38:02 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/22 20:40:59 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_cut(char *str)
{
	int i;
	int cut;

	i = 0;
	while ((str[i] == '\t' || str[i] == ' ' || str[i] == '\n')
	&& (str[i] != '\0'))
		++i;
	if (str[i] == '\0')
		return (0);
	cut = 0;
	while (str[i] != 0)
	{
		if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		&& (str[i + 1] != ' ') && (str[i + 1] != '\t') && (str[i + 1] != '\n')
		&& (str[i + 1] != '\0'))
			++cut;
		++i;
	}
	++cut;
	return (cut);
}

int		ft_w_leng(char *str)
{
	int i;

	i = 0;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

char	**ft_split_whitespaces(char *str)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	if (!(tab = (char**)malloc(sizeof(char*) * (ft_cut(str) + 1))))
		return (0);
	k = ft_cut(str);
	i = -1;
	while (++i < k)
	{
		while ((*str == '\t' || *str == ' ' || *str == '\n')
		&& *str != '\0')
			str++;
		j = 0;
		if (!(tab[i] = (char*)malloc(sizeof(char) * (ft_w_leng(str) + 1))))
			return (0);
		while (*str != '\t' && *str != ' ' && *str != '\n'
		&& *str != '\0')
			tab[i][j++] = *str++;
		tab[i][j] = '\0';
	}
	tab[i] = 0;
	return (tab);
}
