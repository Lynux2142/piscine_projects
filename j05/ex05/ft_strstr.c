/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 12:50:41 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/15 21:42:15 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	char	*new_str;
	char	*s1;
	char	*s2;

	i = 0;
	new_str = str;
	if (to_find[0] == '\0')
		return (str);
	while (new_str[i] != '\0')
	{
		s1 = new_str;
		s2 = to_find;
		while ((s1[i] != '\0') && (s2[i] != '\0') && (s1[i] == s2[i]))
		{
			s1++;
			s2++;
		}
		if (s2[i] == '\0')
			return (new_str);
		new_str++;
	}
	return ("(null)");
}
