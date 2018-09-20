/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 11:22:19 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/14 14:06:43 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (s1[j] == ' ')
		j++;
	while (s1[j] == s2[i] || (s1[j] == ' ' && s2[i] == '\0'))
	{
		if ((s1[j] == '\0' && s2[i] == '\0')
		|| (s1[j] == ' ' && s2[i] == '\0'))
			return (0);
		i++;
		j++;
	}
	return (s1[j] - s2[i]);
}

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

char	ft_spy(char *str)
{
	if ((ft_strcmp(str, "president") == 0) || (ft_strcmp(str, "attack") == 0)
	|| (ft_strcmp(str, "powers") == 0))
		write(1, "Alert!!!\n", 9);
	return (0);
}

int		main(int argc, char **argv)
{
	int i;

	(void)argc;
	i = 0;
	while (argv[i] != '\0')
	{
		ft_strlowcase(argv[i]);
		ft_spy(argv[i]);
		i++;
	}
	return (0);
}
