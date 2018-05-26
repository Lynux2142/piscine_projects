/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 11:05:25 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/16 16:47:23 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	leng_dest;
	unsigned int	leng_src;

	leng_src = 0;
	while (src[leng_src] != '\0')
		leng_src++;
	leng_dest = 0;
	while (src[leng_dest] != '\0' && leng_dest < (size - 1))
	{
		dest[leng_dest] = src[leng_dest];
		leng_dest++;
	}
	dest[leng_dest] = '\0';
	return (leng_src);
}
