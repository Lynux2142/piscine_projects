/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 19:57:14 by exam              #+#    #+#             */
/*   Updated: 2017/07/14 20:17:37 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*alpha_mirror(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (str[i] == 'a')
				str[i] = 'z';
			else
				str[i] = 'a' + ('z' - str[i]);
		}
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (str[i] == 'A')
				str[i] = 'Z';
			else
				str[i] = 'A' + ('Z' - str[i]);
		}
		i++;
	}
	str[i] = '\0';
	i = -1;
	while (str[++i] != '\0')
		ft_putchar(str[i]);
	return (str);
}

int		main(int argc, char **argv)
{
	(void)argv[1];
	if (argv[1] != NULL)
		alpha_mirror(argv[1]);
	ft_putchar('\n');
	return (0);
}
