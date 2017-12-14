/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:09:46 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/14 12:57:57 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int		get_next_line(const int fd, char **line)
{
	char		*buff;
	static int	curs = 0;
	int			i;
	int			save;

	ft_memdel((void *)&(*line));
	if (!(buff = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE)))
		return (0);
	if (!read(fd, buff, BUFF_SIZE))
		return (0);
	ft_putendl(ft_itoa(curs));
	if (curs != 0)
		++curs;
	save = curs;
	while (buff[curs] && buff[curs] != '\n')
		++curs;
	if (!(*line = ft_memalloc(sizeof(*line) * ((curs - save) + 1))))
		return (0);
	i = -1;
	while ((++i + save) < curs)
		*(*line + i) = buff[save + i];
	*(*line + i) = '\0';
	ft_memdel((void *)&buff);
	return (0);
}
