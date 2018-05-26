/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 20:37:00 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/09 20:03:52 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int div_result;
	int mod_result;

	div_result = (*a) / (*b);
	mod_result = (*a) % (*b);
	*a = div_result;
	*b = mod_result;
}
