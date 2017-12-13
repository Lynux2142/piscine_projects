/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:09:46 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/13 11:22:57 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int		get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE];
	static int	curs = 0;
	int			i;
	int			save;

	ft_memdel((void *)&(*line));
	read(fd, buff, BUFF_SIZE);
	if (curs != 0)
		++curs;
	save = curs;
	while (buff[curs] && buff[curs] != '\n')
		++curs;
	if (!(*line = (char *)ft_memalloc(sizeof(char) * ((curs - save) + 1))))
		return (-1);
	i = -1;
	while ((++i + save) < curs)
		*(*line + i) = buff[save + i];
	*(*line + i) = '\0';
	return (0);
}
