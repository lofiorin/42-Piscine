/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:19:35 by lofiorin          #+#    #+#             */
/*   Updated: 2023/09/10 21:19:39 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int appoggio;

	i = 0;
	while(i < (size / 2))
	{
		appoggio = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = appoggio;
		i++;
	}
}
