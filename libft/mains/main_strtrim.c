/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strtrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:54:33 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/16 16:39:16 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_print_result(char const *s)
{
	int	len;

	len = 0;
	while(s[len])
		++len;
	write(1, s, len);
}

int		main(int argc, const char *argv[])
{
	char	*strtrim;
	int		arg;

	if (argc == 1)
		return (0);
	else if ((arg = atoi(argv[1])) == 1)
	{
		char s1[] = "lorem \n ipsum \t dolor \n sit \t amet";
		if (!(strtrim = ft_strtrim(s1)))
			ft_print_result("NULL");
		else
			ft_print_result(strtrim);
		if (strtrim == s1)
			ft_print_result("\nA new string was not returned");
	}
	else if (arg == 2)
	{
		char s1[] = "lorem ipsum dolor sit amet \n \t ";
		if (!(strtrim = ft_strtrim(s1)))
			ft_print_result("NULL");
		else
			ft_print_result(strtrim);
		if (strtrim == s1)
			ft_print_result("\nA new string was not returned");
	}
	else if (arg == 3)
	{
		char s1[] = " \n \t lorem ipsum dolor sit amet";
		if (!(strtrim = ft_strtrim(s1)))
			ft_print_result("NULL");
		else
			ft_print_result(strtrim);
		if (strtrim == s1)
			ft_print_result("\nA new string was not returned");
	}
	else if (arg == 4)
	{
		char s1[] = "  \n  \t  lorem \n ipsum \t dolor \n sit \t amet  \t \n ";
		if (!(strtrim = ft_strtrim(s1)))
			ft_print_result("NULL");
		else
			ft_print_result(strtrim);
		if (strtrim == s1)
			ft_print_result("\nA new string was not returned");
	}
	else if (arg == 5)
	{
		char s1[] = "          ";
		if (!(strtrim = ft_strtrim(s1)))
			ft_print_result("NULL");
		else
			ft_print_result(strtrim);
		if (strtrim == s1)
			ft_print_result("\nA new string was not returned");
	}
	return (0);
}
