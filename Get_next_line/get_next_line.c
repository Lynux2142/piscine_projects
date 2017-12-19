/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:09:46 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/19 17:02:07 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static char		*ft_memrealloc(void *s1, void *s2, int len)
{
	int		len_s1;
	int		i;

	if (s1)
	{
		len_s1 = ft_strlen((char *)s1);
		if (!(s2 = (void *)ft_memalloc(sizeof(void) * (len_s1 + len))))
			return (NULL);
		i = -1;
		while (*(char *)(s1 + (++i)))
			*(char *)(s2 + i) = *(char *)(s1 + i);
	}
	else
	{
		if (!(s2 = (void *)ft_memalloc(sizeof(void) * len)))
			return (NULL);
	}
	return (s2);
}

int				get_next_line(const int fd, char **line)
{
	static char	buff[BUFF_SIZE];
	static int	curs = 0;
	int			i;
	int			save;
	int			ok;

	ok = 0;
	while (!ok)
	{
		if (curs != 0)
			++curs;
		else
			read(fd, buff, BUFF_SIZE);
		save = curs;
		while (buff[curs] && buff[curs] != '\n')
			++curs;
		if (buff[curs] == '\n')
			ok = 1;
		if (!(*line = (char *)ft_memrealloc(*line, *line, sizeof(char) * ((curs - save) + 1))))
			return (0);
		i = -1;
		while ((++i + save) < curs)
			*(*line + i) = buff[save + i];
		*(*line + i) = '\0';
		ft_bzero((void *)buff, (curs - save));
		curs = (buff[curs] == '\0') ? 0 : curs;
	}
	return (1);
}
