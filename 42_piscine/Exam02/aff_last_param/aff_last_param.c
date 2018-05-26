/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_last_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 18:19:30 by exam              #+#    #+#             */
/*   Updated: 2017/07/21 18:31:20 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int i;
	int j;

	if (argc == 1)
	{
		ft_putchar('\n');
		return (0);
	}
	i = 0;
	j = (argc - 1);
	while (argv[j][i] != '\0')
	{
		ft_putchar(argv[j][i]);
		++i;
	}
	ft_putchar('\n');
	return (0);
}
