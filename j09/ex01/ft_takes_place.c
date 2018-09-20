/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:46:21 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/16 09:04:17 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_takes_place(int hour)
{
	write(1, "THE FOLLOWING TAKES PLACE BETWEEN ", 34);
	if (hour == 12)
		printf("%d.00 P.M. AND %d.00 P.M.\n", hour, hour - 11);
	if (hour == 0)
		printf("%d.00 A.M. AND %d.00 A.M.\n", hour + 12, hour + 1);
	if (hour == 11)
		printf("%d.00 A.M. AND %d.00 P.M.\n", hour, hour + 1);
	if (hour == 23)
		printf("%d.00 P.M. AND %d.00 A.M.\n", hour - 12, hour - 11);
	if (hour < 11 && hour > 0)
		printf("%d.00 A.M. AND %d.00 A.M.\n", hour, hour + 1);
	if (hour > 12 && hour < 23)
		printf("%d.00 P.M. AND %d.00 P.M.\n", hour - 12, hour - 11);
}
