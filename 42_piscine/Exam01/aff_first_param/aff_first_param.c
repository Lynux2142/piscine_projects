/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_first_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 18:03:47 by exam              #+#    #+#             */
/*   Updated: 2017/07/15 08:57:28 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(int argc, char **argv)
{
	argc++;
	(void)argv[1];
	if (argv[1] == NULL)
		printf("\n");
	else
		printf("%s\n", argv[1]);
	return (0);
}
