/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:07:40 by lofiorin          #+#    #+#             */
/*   Updated: 2023/09/18 19:07:42 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	b;

	b = nb;
	if (b < 0)
	{
		ft_putchar('-');
		b = -b;
	}
	if (b >= 10)
	{
		ft_putnbr(b / 10);
	}
	ft_putchar('0' + b % 10);
}
