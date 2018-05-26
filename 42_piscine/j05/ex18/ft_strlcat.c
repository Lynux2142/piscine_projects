/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 11:01:48 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/17 17:11:44 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	result;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	while (dest[j] != '\0')
		j++;
	result = i + j;
	if (j >= size)
		result = i + size;
	i = 0;
	while (src[i] != '\0' && j < size)
		dest[j++] = src[i++];
	dest[j] = '\0';
	return (result);
}
