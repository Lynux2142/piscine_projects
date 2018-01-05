/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 12:30:52 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/04 16:48:48 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./get_next_line.h"
#include <unistd.h>

#define MDP "123456"

int		main(void)
{
	char	*line;

	ft_putstr("Entrez votre mot de passe : ");
	get_next_line(0, &line);
	while (ft_strcmp(MDP, line))
	{
		ft_putendl("mauvais mot de passe\n");
		ft_putstr("Entrez votre mot de passe : ");
		get_next_line(0, &line);
	}
	ft_putendl("mot de passe correct");
	ft_memdel((void *)&line);
	return (0);
}
