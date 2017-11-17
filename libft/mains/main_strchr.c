/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:02:24 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/15 11:40:42 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int		main(void)
{
	char	*src = "\0";
	char	*mdr1 = ft_strchr(src, 'a');
	char	*mdr2 = strchr(src, 'a');

	printf("%s\n", mdr1);
	printf("%s\n", mdr2);
	return (0);
}
