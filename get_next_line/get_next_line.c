/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:24:31 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/22 15:58:29 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <unistd.h>

static char	ft_getchar(const int fd)
{
	static char	buff[BUFF_SIZE];
	static char	*str;
	static int	len = 0;
	char		c;

	if (len == 0)
	{
		len = read(fd, buff, BUFF_SIZE);
		str = (char *)&buff;
		if (len == 0 || len == -1)
			return (len);
	}
	c = *str;
	++str;
	--len;
	return (c);
}

int			get_next_line(const int fd, char **line)
{
	char	c;
	int		len;

	if (line == NULL)
		return (-1);
	len = 0;
	*line = ft_strnew(BUFF_SIZE);
	if (*line == NULL)
		return (0);
	c = ft_getchar(fd);
	while (c != '\n' && c != '\0' && c != 0 && c != -1)
	{
		line[0][len] = c;
		c = ft_getchar(fd);
		++len;
		if ((len % BUFF_SIZE + 1) == 0)
			*line = ft_memrealloc(*line, len + BUFF_SIZE + 1);
	}
	line[0][len] = '\0';
	if (c == -1)
		return (c);
	if (line[0][0] == '\0')
		return (0);
	return (1);
}
