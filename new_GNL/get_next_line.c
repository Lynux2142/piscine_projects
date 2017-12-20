/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:09:46 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/20 17:50:26 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static int			ft_qwerty(char **line, char *buff)
{
	char		*tmp;
	static int	curs = 0;
	static int	i = 0;
	int			len;

	if (!(tmp = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE)))
		return (0);
	i = curs;
	while (buff[curs] && buff[curs] != '\n')
		++curs;
	len = curs - i;
	if (!(*line = (char *)ft_memalloc(sizeof(char) * len)))
		return (0);
	if (buff[curs] == '\n' && buff[curs + 1] != '\0')
	{
		i = -1;
		while (buff[++curs])
			tmp[++i] = buff[curs];
	}
	i = -1;
	while (++i < len)
	{
		*(*line + i) = buff[i];
	}
	ft_memdel((void *)&tmp);
	return (buff[curs] / '\n');
}

int				get_next_line(const int fd, char **line)
{
	static char	buff[BUFF_SIZE];

	ft_bzero(buff, BUFF_SIZE);
	while (ft_qwerty(line, buff) != 1)
	{
		read(fd, buff, BUFF_SIZE);
	}
	return (1);
}
