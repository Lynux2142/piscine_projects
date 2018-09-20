/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scrambler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 09:41:13 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/14 10:09:48 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_scrambler(int ***a, int *b, int *******c, int ****d)
{
	int temp_a;
	int temp_b;
	int temp_c;
	int temp_d;

	temp_a = ***a;
	temp_b = *b;
	temp_c = *******c;
	temp_d = ****d;
	***a = temp_b;
	*b = temp_d;
	*******c = temp_a;
	****d = temp_c;
}
