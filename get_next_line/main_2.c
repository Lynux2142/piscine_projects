/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 12:28:30 by lguiller          #+#    #+#             */
/*   Updated: 2017/12/23 12:43:53 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <unistd.h>
#include <assert.h>

int		main(void)
{
	char	*line;
	int		out;
	int		p[2];
	int		fd;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abcdefgh\n", 9);
	write(fd, "ijklmnop\n", 9);
	write(fd, "qrstuvwx\n", 9);
	write(fd, "yzabcdef\n", 9);
	write(fd, "ghijklmn\n", 9);
	write(fd, "opqrstuv\n", 9);
	write(fd, "wxyzabcd\n", 9);
	close(p[1]);
	dup2(out, fd);
	get_next_line(p[0], &line);
	assert(ft_strcmp(line, "abcdefgh") == 0);
	ft_memdel((void *)&line);
	get_next_line(p[0], &line);
	assert(ft_strcmp(line, "ijklmnop") == 0);
	ft_memdel((void *)&line);
	get_next_line(p[0], &line);
	assert(ft_strcmp(line, "qrstuvwx") == 0);
	ft_memdel((void *)&line);
	get_next_line(p[0], &line);
	assert(ft_strcmp(line, "yzabcdef") == 0);
	ft_memdel((void *)&line);
	get_next_line(p[0], &line);
	assert(ft_strcmp(line, "ghijklmn") == 0);
	ft_memdel((void *)&line);
	get_next_line(p[0], &line);
	assert(ft_strcmp(line, "opqrstuv") == 0);
	ft_memdel((void *)&line);
	get_next_line(p[0], &line);
	assert(ft_strcmp(line, "wxyzabcd") == 0);
	ft_memdel((void *)&line);
	close(p[0]);
	return (0);
}
