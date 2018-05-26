/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 15:15:14 by exam              #+#    #+#             */
/*   Updated: 2017/07/28 15:38:27 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_rev_print(char **tab, int length)
{
	int i;
	int j;
	char *temp;

	i = 0;
	j = (length - 1);
	while (i <= j)
	{
		temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;
		--j;
		++i;
	}
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			ft_putchar(tab[i][j]);
			++j;
		}
		if (tab[i + 1] != 0)
			write(1, " ", 1);
		++i;
	}
	write(1, "\n", 1);
}

int		ft_count_word(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			if (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0')
				++count;
		}
		++i;
	}
	return (count);
}

int		ft_length(char *str, int nb)
{
	int i;

	i = 0;
	while (str[nb + i] != ' ' && str[nb + i] != '\t' && str[nb + i] != '\0')
		++i;
	return (i);
}

char	**ft_split(char *str)
{
	int i;
	int j;
	int k;
	char **tab;

	if (!(tab = (char**)malloc(sizeof(char*) * (ft_count_word(str) + 1))))
		return (0);
	k = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
		{
			if (str[i + 1] == '\0')
				return (0);
			++i;
		}
		if (!(tab[k] = (char*)malloc(sizeof(char) * (ft_length(str, i) + 1))))
			return (0);
		j = 0;
		while (str[i] != ' ' && str[i] != '\t' && str[i])
			tab[k][j++] = str[i++];
		tab[k][j] = '\0';
		++k;
		while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
			++i;
	}
	tab[k] = NULL;
	return (tab);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	ft_rev_print(ft_split(argv[1]), ft_count_word(argv[1]));
	return (0);
}
