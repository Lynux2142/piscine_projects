/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:57:03 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/10 15:57:55 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int		main(void)
{
	int a;
	char *b;

	b = "25";
	a = 5 * ft_atoi(b);
	printf("%d", a);
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("1 - '  @@ -1,8 +1,8 @@$' - '%d'\n", ft_atoi("  @@ -1,8 +1,8 @@$"));
	printf("1 - '456' - '%d'\n", ft_atoi("456"));
	printf("2 - ' -456' - '%d'\n", ft_atoi(" -456"));
	printf("3 - '45' - '%d'\n", ft_atoi("45$"));
	printf("4 - '0' - '%d'\n", ft_atoi("0"));
	printf("5 - '     ' - '%d'\n", ft_atoi("     "));
	printf("6 - '12,1' - '%d'\n", ft_atoi("12,1"));
	printf("7 - 'abcd' - '%d'\n", ft_atoi("abcd"));
	printf("8 - 'abcd123' - '%d'\n", ft_atoi("abcd123"));
	printf("9 - 'a1b2c3' - '%d'\n", ft_atoi("a1b2c3"));
	printf("10 - '14a' - '%d'\n", ft_atoi("14a"));
	printf("11 - '14 ' - '%d'\n", ft_atoi("14 "));
	printf("12 - '14 9' - '%d'\n", ft_atoi("14 9"));
	printf("13 - ' 9' - '%d'\n", ft_atoi(" 9"));
	printf("14 - ' - 9' - '%d'\n", ft_atoi(" - 9"));
	printf("15 - '-2147483648' - '%d'\n", ft_atoi("-2147483648"));
	printf("15 - '-99999999999999999999999999' - '%d'\n", ft_atoi("-99999999999999999999999999"));
	printf("16 - '+48' - '%d'\n", ft_atoi("+48"));
	printf("16 - '\t\n\v\f\r48' - '%d'\n", ft_atoi("\t\n\v\f\r48"));
	printf("----------------\n");
	printf("1 - '  @@ -1,8 +1,8 @@$' - '%d'\n", atoi("  @@ -1,8 +1,8 @@$"));
	printf("1 - '456' - '%d'\n", atoi("456"));
	printf("2 - ' -456' '%d'\n", atoi(" -456"));
	printf("3 - '45' - '%d'\n", atoi("45$"));
	printf("4 - '0' - '%d'\n", atoi("0"));
	printf("5 - '     ' - '%d'\n", atoi("     "));
	printf("6 - '12,1' - '%d'\n", atoi("12,1"));
	printf("7 - 'abcd' - '%d'\n", atoi("abcd"));
	printf("8 - 'abcd123' - '%d'\n", atoi("abcd123"));
	printf("9 - 'a1b2c3' - '%d'\n", atoi("a1b2c3"));
	printf("10 - '14a' - '%d'\n", atoi("14a"));
	printf("11 - '14 ' - '%d'\n", atoi("14 "));
	printf("12 - '14 9' - '%d'\n", atoi("14 9"));
	printf("13 - ' 9' - '%d'\n", atoi(" 9"));
	printf("14 - ' - 9' - '%d'\n", atoi(" - 9"));
	printf("15 - '-2147483648' - '%d'\n", atoi("-2147483648"));
	printf("15 - '-99999999999999999999999999' - '%d'\n", atoi("-99999999999999999999999999"));
	printf("16 - '+48' - '%d'\n", atoi("+48"));
	printf("16 - '\t\n\v\f\r48' - '%d'\n", atoi("\t\n\v\f\r48"));
	return (0);
}
