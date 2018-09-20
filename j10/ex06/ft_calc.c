/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 09:15:55 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/25 10:22:08 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_plus(int frst, int scnd)
{
	int result;

	result = frst + scnd;
	ft_print_result(result);
}

void	ft_minus(int frst, int scnd)
{
	int result;

	result = frst - scnd;
	ft_print_result(result);
}

void	ft_multiply(int frst, int scnd)
{
	int result;

	result = frst * scnd;
	ft_print_result(result);
}

void	ft_divide(int frst, int scnd)
{
	int result;

	result = frst / scnd;
	ft_print_result(result);
}

void	ft_modulo(int frst, int scnd)
{
	int result;

	result = frst % scnd;
	ft_print_result(result);
}
