/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:09:46 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/18 16:10:46 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int			get_next_line(const int fd, char **line)
{
	static char	buff[BUFF_SIZE];
	static int	curs = 0;
	int			i;
	int			save;

	if (curs != 0)
		++curs;
	else
		read(fd, buff, BUFF_SIZE);
	save = curs;
	while (buff[curs] && buff[curs] != '\n')
		++curs;
	if (!(*line = (char *)ft_memalloc(sizeof(char) * ((curs - save) + 1))))
		return (0);
	i = -1;
	while ((++i + save) < curs)
		*(*line + i) = buff[save + i];
	*(*line + i) = '\0';
	ft_bzero((void *)buff, (curs - save));
	curs = (buff[curs] == '\0') ? 0 : curs;
	return (1);
}
