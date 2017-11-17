/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:50:18 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/15 12:58:06 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int		main(void)
{
	char	*str = "Hello les genw";
	char	*str2 = "A";

	printf("%s  ---  %s\n", strnstr(str, "Hello", 6), ft_strnstr(str, "Hello", 6));
	printf("%s  ---  %s\n", strnstr(str, "Hello", 3), ft_strnstr(str, "Hello", 3));
	printf("%s  ---  %s\n", strnstr(str, "les", 1), ft_strnstr(str, "les", 1));
	printf("%s  ---  %s\n", strnstr(str, "gen", 2), ft_strnstr(str, "gen", 2));
	printf("%s  ---  %s\n", strnstr(str, "w", 0), ft_strnstr(str, "w", 0));
	printf("%s  ---  %s\n", strnstr(str, "", 3), ft_strnstr(str, "", 3));
	printf("%s  ---  %s\n", strnstr(str2, str2, 2), ft_strnstr(str2, str2, 2));
	return (0);
}
