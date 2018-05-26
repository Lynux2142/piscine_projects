/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 21:44:07 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/13 08:29:02 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'A') && (str[i] <= 'Z'))
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	ft_strlowcase(str);
	while (str[i + 1] != '\0')
	{
		if ((str[0] > 'a') && (str[0] < 'z'))
		{
			str[0] -= 32;
			i++;
		}
		if (((str[i - 1] < '0') || ((str[i - 1] > '9') && (str[i - 1] < 'A'))
		|| ((str[i - 1] > 'Z') && (str[i - 1] < 'a')) || (str[i - 1] > 'z'))
		&& ((str[i] >= 'a') && (str[i] <= 'z')))
			str[i] -= 32;
		i++;
	}
	return (str);
}
