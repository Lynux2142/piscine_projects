/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 21:58:48 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/11 11:26:10 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_fibonacci(int index)
{
	int result;

	if ((index < 0) || (index > 46))
		return (-1);
	else if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else
		result = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	return (result);
}
