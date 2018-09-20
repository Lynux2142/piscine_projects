/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perso.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 15:28:05 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/14 15:57:29 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PERSO_H
# define FT_PERSO_H

# include <string.h>

# define SAVE_THE_WORLD "42"

typedef struct			s_perso
{
	char			*name;
	float			life;
	unsigned int	age;
	char			*profession;
}						t_perso;

#endif
