/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:03:26 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/14 12:15:44 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_takes_place(int hour);

int		main(int argc, char **argv)
{
	(void)argc;
	ft_takes_place(atoi(argv[1]));
	return (0);
}
