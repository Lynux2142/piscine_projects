/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:14:39 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/13 11:59:32 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int i;
	int negativ;
	int nb;

	i = 0;
	negativ = 0;
	nb = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
			|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		negativ = 1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nb *= 10;
		nb += (str[i] - 48);
		i++;
	}
	if (negativ == 1)
		return (-nb);
	else
		return (nb);
}
