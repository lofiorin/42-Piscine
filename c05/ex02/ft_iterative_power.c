/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 23:59:33 by lofiorin          #+#    #+#             */
/*   Updated: 2023/09/18 23:59:35 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	risultato;

	risultato = 1;
	while (power > 0)
	{
		risultato *= nb;
		power--;
	}
	if (power < 0)
		return (0);
	return (risultato);
}
