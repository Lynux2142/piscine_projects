/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 10:27:45 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/17 10:33:13 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		nmatch(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 == '*' && *s2 == '*')
		return (nmatch(s1 + 1, s2));
	if (*s1 != '\0' && *s2 == '*')
		return ((nmatch(s1 + 1, s2)) + (nmatch(s1, s2 + 1)));
	if (*s1 == '\0' && *s2 == '*')
		return (nmatch(s1, s2 + 1));
	if (*s1 == *s2)
		return (nmatch(s1 + 1, s2 + 1));
	return (0);
}
