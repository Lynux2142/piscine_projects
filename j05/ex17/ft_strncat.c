/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 10:50:08 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/17 09:13:01 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, int nb)
{
	int leng;
	int j;

	leng = 0;
	while (dest[leng] != '\0')
		leng++;
	j = 0;
	while (src[j] != '\0' && j < nb)
		dest[leng++] = src[j++];
	dest[leng++] = '\0';
	return (dest);
}
