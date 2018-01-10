/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:24:31 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/10 17:37:40 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static char	ft_getchar(const int fd, int *rd_len, t_struct *var)
{
	char		c;

	if (var->len == 0)
	{
		if ((*rd_len = read(fd, var->buff, BUFF_SIZE)) <= 0)
			return ((*rd_len == 0) ? 0 : -1);
		var->len = *rd_len;
		var->str = (char *)&var->buff;
	}
	c = var->str[0];
	++var->str;
	--var->len;
	return (c);
}

int			get_next_line(const int fd, char **line)
{
	static t_struct	var;
	char			c;
	int				len;

	if (line == NULL || fd < 0)
		return (-1);
	len = 0;
	if (!(*line = ft_strnew(BUFF_SIZE)))
		return (0);
	if ((c = ft_getchar(fd, &var.rd_len, &var)) == -1)
		return (-1);
	while (c != '\n' && var.rd_len > 0)
	{
		if (c == -1)
			return (-1);
		line[0][len] = c;
		c = ft_getchar(fd, &var.rd_len, &var);
		++len;
		if ((len % BUFF_SIZE) == 0)
			*line = ft_realloc(*line, len + BUFF_SIZE + 1);
	}
	line[0][len] = '\0';
	return ((**line == '\0' && c != '\n') ? 0 : 1);
}
