/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 09:22:20 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/17 17:54:34 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int leng;
	int j;

	leng = 0;
	while (dest[leng] != '\0')
		leng++;
	j = 0;
	while (src[j] != '\0')
		dest[leng++] = src[j++];
	dest[leng++] = '\0';
	return (dest);
}
