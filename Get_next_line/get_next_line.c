/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:09:46 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/20 13:34:58 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static char		*ft_memrealloc(void *s1, int len)
{
	int		len_s1;
	void	*s2;

	if (s1)
	{
		len_s1 = ft_strlen((char *)s1);
		if (!(s2 = ft_memalloc((len_s1 + len))))
			return (NULL);
		s2 = (char *)ft_memcpy(s2, s1, len_s1);
		ft_memdel(&s1);
	}
	else
	{
		if (!(s2 = ft_memalloc(len)))
			return (NULL);
	}
	return ((char *)s2);
}

int				get_next_line(const int fd, char **line)
{
	static char	buff[BUFF_SIZE];
	static int	curs = 0;
	static int	i = -1;
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
		{
			if (!(*line = (char *)ft_memrealloc(*line, sizeof(char) * ((curs - save) + 1))))
				return (0);
			while ((++i + save) < curs)
				*(*line + i) = buff[save + i];
			*(*line + i) = '\0';
			--i;
			ft_bzero((void *)buff, (curs - save));
			curs = (buff[curs] == '\0') ? 0 : curs;
			ok = 1;
			i = -1;
		}
		else
		{
			if (!(*line = (char *)ft_memrealloc(*line, sizeof(char) * ((curs - save) + 1))))
				return (0);
			while ((++i + save) < curs)
				*(*line + i) = buff[save + i];
			*(*line + i) = '\0';
			--i;
			ft_bzero((void *)buff, (curs - save));
			curs = (buff[curs] == '\0') ? 0 : curs;
		}
	}
	return (1);
}
