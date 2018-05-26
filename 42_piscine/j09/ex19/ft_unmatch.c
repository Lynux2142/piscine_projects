/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 10:47:27 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/14 16:48:02 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_unmatch(int *tab, int length)
{
	int i;
	int j;
	int result;

	length--;
	result = 0;
	j = length;
	i = 0;
	while (j != 0)
	{
		while (i != length)
		{
			if ((tab[i] == tab[j]) && (i != j))
			{
				tab[i] = 0;
				tab[j] = 0;
				break ;
			}
			i++;
		}
		j--;
	}
	while (length >= 0)
	{
		result += tab[length];
		length--;
	}
	return (result);
}
