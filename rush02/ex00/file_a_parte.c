/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_a_parte.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:29:28 by lofiorin          #+#    #+#             */
/*   Updated: 2023/09/24 22:29:37 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

long	getdec(long nb)
{
	if (nb >= 90)
		return (90);
	else if (nb >= 80)
		return (80);
	else if (nb >= 70)
		return (70);
	else if (nb >= 60)
		return (60);
	else if (nb >= 50)
		return (50);
	else if (nb >= 40)
		return (40);
	else if (nb >= 30)
		return (30);
	else if (nb >= 20)
		return (20);
	else if (nb <= 20)
		return (nb);
	else
		return (0);
}

long	getmult(long nb)
{
	if (nb >= 1000000000)
		return (1000000000);
	else if (nb >= 1000000)
		return (1000000);
	else if (nb >= 1000)
		return (1000);
	else if (nb >= 100)
		return (100);
	else
		return (getdec(nb));
}

void	ft_print(long n, t_dielement *dict, int first)
{
	int		i;
	long	mult;

	i = 0;
	mult = getmult(n);
	if (mult >= 100)
		ft_print(n / mult, dict, first);
	if (first == 0)
		write(1, " ", 1);
	first = 0;
	while (dict[i].key != mult)
		i++;
	ft_putstr(dict[i].value);
	if (mult != 0 && n % mult != 0)
		ft_print(n % mult, dict, first);
}
