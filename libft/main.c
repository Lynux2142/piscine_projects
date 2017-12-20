/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:08:14 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/18 18:09:31 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(int ac, char **av)
{
	(void)ac;
	if (ft_brackets(av[1]))
		ft_putstr("OK\n");
	else
		ft_putstr("Error\n");
	return (0);
}