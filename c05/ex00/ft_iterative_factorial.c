/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 23:46:52 by lofiorin          #+#    #+#             */
/*   Updated: 2023/09/18 23:46:54 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	fattoriale;

	fattoriale = 1;
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	while (nb != 0)
	{
		fattoriale = fattoriale * nb;
		nb--;
	}
	return (fattoriale);
}
