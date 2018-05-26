/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 11:14:17 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/25 16:28:48 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count(char **str)
{
	int i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		++i;
	}
	return (s1[i] - s2[i]);
}

void	ft_sort_wordtab(char **tab)
{
	int		i;
	int		j;
	char	*temp;

	i = ft_count(tab);
	while (i > 0)
	{
		j = 0;
		while (j < (ft_count(tab) - 1))
		{
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
			{
				temp = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = temp;
			}
			++j;
		}
		--i;
	}
}
