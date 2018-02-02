/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 16:33:38 by lguiller          #+#    #+#             */
/*   Updated: 2018/02/01 16:33:40 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	ft_calc(int nb, float *list, char ope)
{
	float	value;
	int		i;

	i = 0;
	value = list[i];
	while (++i < nb)
	{
		if (ope == '+')
			value += list[i];
		else if (ope == '-')
			value -= list[i];
		else if (ope == '*')
			value *= list[i];
		else if (ope == '/')
			value /= list[i];
	}
	printf("resultat = %f\n", value);
}

int		check_ope(char ope)
{
	if (ope != '+' && ope != '-' && ope != '*' && ope != '/')
	{
		printf("Operateur non valide.\n");
		printf("operateur: ");
		return (0);
	}
	return (1);
}

int		main(void)
{
	int		nb;
	int		i;
	char	ope;
	float	*list;

	printf("nombre de chiffres: ");
	scanf("%d", &nb);
	getchar();
	if (!(list = (float *)malloc(sizeof(float) * nb)))
		return(-1);
	i = -1;
	while (++i < nb)
	{
		printf("chiffre %d: ", i + 1);
		scanf("%f", &list[i]);
		getchar();
	}
	printf("operateur: ");
	scanf("%c", &ope);
	getchar();
	while (!check_ope(ope))
	{
		scanf("%c", &ope);
		getchar();
	}
	ft_calc(nb, list, ope);
	return (0);
}
