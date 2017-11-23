/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:19:26 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/23 11:45:31 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static char	*ft_write(char *file, char *tab)
{
	int		fd;
	char	buf;
	int		i;

	if (!(fd = open(file, O_RDONLY)))
		return (NULL);
	i = 0;
	while (read(fd, &buf, 1) > 0)
		tab[i++] = buf;
	close(fd);
	return (tab);
}

char		*ft_stock_file(char *file)
{
	int		fd;
	char	buf;
	char	*tab;
	int		i;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	i = 0;
	while (read(fd, &buf, 1) > 0)
		i++;
	if (!(tab = ft_memalloc(i + 1)))
		return (NULL);
	if (!(tab = ft_write(file, tab)))
		return (NULL);
	close(fd);
	return (tab);
}
