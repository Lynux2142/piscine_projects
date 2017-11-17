/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:59:07 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/09 14:07:48 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int		main(void)
{
	char	lol1[25] = "I Love Rock'n Roll !";
	char	lol2[25] = "I Love Rock'n Roll !";

	printf("%s\n", ft_strdup(lol1));
	printf("%s\n", strdup(lol2));
	return (0);
}
