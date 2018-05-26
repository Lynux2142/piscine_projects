/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 20:53:40 by exam              #+#    #+#             */
/*   Updated: 2017/07/14 21:28:32 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_leng(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	i--;
	return (i);
}

void	ft_print(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	wdmatch(char *mot, char *phrase)
{
	int i;
	int j;
	int resultat;

	i = 0;
	j = 0;
	resultat = 0;
	while (mot[i] != '\0')
	{
		while (phrase[j] != '\0')
		{
			if (phrase[j] == mot[i])
				resultat++;
			if (mot[i + 1] == '\0' && resultat == ft_leng(mot))
			{
				ft_print(mot);
				return ;
			}
			else if (phrase[i + 1] == '\0')
			{
				ft_putchar('\n');
				return ;
			}
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	(void)argv[1];
	if (argv[2] == NULL || argv[1] == NULL)
		ft_putchar('\n');
	else
		wdmatch(argv[1], argv[2]);
	return (0);
}
