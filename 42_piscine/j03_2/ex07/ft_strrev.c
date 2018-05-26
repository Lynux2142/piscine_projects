/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 09:31:32 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/11 20:31:16 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		height;
	int		i;
	char	temp;

	height = 0;
	while (str[height] != '\0')
	{
		height++;
	}
	i = 0;
	height--;
	while (i < height)
	{
		temp = str[i];
		str[i] = str[height];
		str[height] = temp;
		i++;
		height--;
	}
	return (str);
}
