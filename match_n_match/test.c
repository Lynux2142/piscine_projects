/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 10:28:42 by lguiller          #+#    #+#             */
/*   Updated: 2017/08/09 20:37:52 by lynux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		match(char *s1, char *s2);

int		main(int argc, char **argv)
{
	(void)argc;
	printf("%d", match(argv[1], argv[2]));
	return (0);
}
