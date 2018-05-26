/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 14:51:06 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/25 17:58:16 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_decrois(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = 0;
	while (i < length)
	{
		if (f(tab[i], tab[i + 1]) > 0 && tab[i + 1])
			return (0);
		++i;
	}
	return (1);
}

int		ft_is_crois(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = 0;
	while (i < length)
	{
		if (f(tab[i], tab[i + 1]) < 0 && tab[i + 1])
			return (0);
		++i;
	}
	return (1);
}

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (length <= 2)
		return (1);
	return (ft_is_crois(tab, length, f) ^ ft_is_decrois(tab, length, f));
}
