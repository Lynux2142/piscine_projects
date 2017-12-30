/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:24:31 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/30 13:56:45 by lguiller         ###   ########.fr       */
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
		if ((len = read(fd, buff, BUFF_SIZE)) <= 0)
			return (len);
		str = (char *)&buff;
	}
	c = str[0];
	++str;
	--len;
	return (c);
}

int			get_next_line(const int fd, char **line)
{
	char	c;
	int		len;

	if (line == NULL || fd < 0)
		return (-1);
	len = 0;
	if (!(line[0] = ft_strnew((size_t)BUFF_SIZE)))
		return (0);
	c = ft_getchar(fd);
	while (c != '\n' && c != '\0')
	{
		if (c == -1)
			return (-1);
		line[0][len] = c;
		c = ft_getchar(fd);
		++len;
		if ((len % BUFF_SIZE + 1) == 0)
			line[0] = ft_memrealloc(line[0], len + BUFF_SIZE + 1);
	}
	line[0][len] = '\0';
	return ((line[0][0] == '\0' && c != '\n') ? 0 : 1);
}
