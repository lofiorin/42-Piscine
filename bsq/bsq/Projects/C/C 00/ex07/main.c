/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 20:43:28 by aperez-b          #+#    #+#             */
/*   Updated: 2021/02/27 20:43:30 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr2(int nb);
void	ft_putnbr(int nb);

int		main(void)
{
	int nb;

	nb = -2147483649;
	ft_putnbr2(nb);
	write(1, "\n", 1);
	ft_putnbr(nb);
}