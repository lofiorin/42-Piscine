/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 21:30:23 by lofiorin          #+#    #+#             */
/*   Updated: 2023/09/10 21:31:53 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;
	int appoggio;
	
	i = 0;
	while(i < size)
	{
		j = i + 1;
		while(j < size)
		{
			if(tab[i] > tab[j])
			{
				appoggio = tab[i];
				tab[i] = tab[j];
				tab[j] = appoggio;
			}
			j++;
		}
		i++;
	}
}
