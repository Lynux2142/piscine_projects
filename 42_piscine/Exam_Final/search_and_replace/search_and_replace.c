/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 10:06:17 by exam              #+#    #+#             */
/*   Updated: 2017/07/28 10:18:09 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		++i;
	}
	write(1, "\n", 1);
}

char	*ft_swap(char *str, char frst, char scnd)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == frst)
			str[i] = scnd;
		++i;
	}
	ft_putstr(str);
	return (str);
}

int		main(int argc, char **argv)
{
	if (argc != 4 || argv[2][1] != '\0' || argv[3][1] != '\0')
	{
		write(1, "\n", 1);
		return (0);
	}
	ft_swap(argv[1], argv[2][0], argv[3][0]);
	return (0);
}
