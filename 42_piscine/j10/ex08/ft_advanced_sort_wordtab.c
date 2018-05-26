/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_wordtab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 15:30:45 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/26 15:31:01 by lguiller         ###   ########.fr       */
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

void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char *))
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
			if (cmp(tab[j], tab[j + 1]) > 0)
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
