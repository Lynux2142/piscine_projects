/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 11:52:24 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/18 17:30:56 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_concat_params(int argc, char **argv)
{
	int		i_j_k[3];
	char	*str;

	str = NULL;
	str = (char*)malloc(sizeof(char) * argc - 1);
	if (str == NULL)
		exit(0);
	i_j_k[0] = 1;
	i_j_k[2] = 0;
	while (argv[i_j_k[0]] != '\0')
	{
		i_j_k[1] = 0;
		while (argv[i_j_k[0]][i_j_k[1]] != '\0')
		{
			str[i_j_k[2]] = argv[i_j_k[0]][i_j_k[1]];
			++i_j_k[1];
			++i_j_k[2];
		}
		str[i_j_k[2]] = '\n';
		++i_j_k[2];
		++i_j_k[0];
	}
	str[i_j_k[2] - 1] = '\0';
	return (str);
}
