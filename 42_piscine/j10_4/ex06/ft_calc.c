/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 09:15:55 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/07 12:55:08 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_plus(int frst, int scnd)
{
	ft_print_result(frst + scnd);
}

void	ft_minus(int frst, int scnd)
{
	ft_print_result(frst - scnd);
}

void	ft_multiply(int frst, int scnd)
{
	ft_print_result(frst * scnd);
}

void	ft_divide(int frst, int scnd)
{
	ft_print_result(frst / scnd);
}

void	ft_modulo(int frst, int scnd)
{
	ft_print_result(frst % scnd);
}
