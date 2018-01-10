/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:24:31 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/10 15:51:06 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "get_next_line.h"
#include <unistd.h>

static char	ft_getchar(const int fd, int *rd_len)
{
	static char	buff[BUFF_SIZE];
	static char	*str;
	static int	len = 0;
	char		c;

	if (len == 0)
	{
		if ((*rd_len = read(fd, buff, BUFF_SIZE)) <= 0)
			return ((*rd_len == 0) ? 0 : -1);
		len = *rd_len;
		str = (char *)&buff;
	}
	c = str[0];
	++str;
	--len;
	return (c);
}

int			get_next_line(const int fd, char **line)
{
	char		c;
	int			len;
	static int	rd_len = 0;

	if (line == NULL || fd < 0)
		return (-1);
	len = 0;
	if (!(*line = ft_strnew(BUFF_SIZE)))
		return (0);
	if ((c = ft_getchar(fd, &rd_len)) == -1)
		return (-1);
	while (c != '\n' && rd_len > 0)
	{
		if (c == -1)
			return (-1);
		line[0][len] = c;
		c = ft_getchar(fd, &rd_len);
		++len;
		if ((len % BUFF_SIZE) == 0)
			*line = ft_realloc(*line, len + BUFF_SIZE + 1);
	}
	line[0][len] = '\0';
	return ((**line == '\0' && c != '\n') ? 0 : 1);
}
