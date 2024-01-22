/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stampa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 23:30:30 by anomourn          #+#    #+#             */
/*   Updated: 2023/09/17 23:31:05 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	stampa(int tab[4][4][4], int ord)
{
	int	i;
	int	j;
	int	k;
	char	c;

	i = 0;
	while (i < ord)
	{
		j = 0;
		while (j < ord)
		{
			k = 0;
			while (k < ord)
			{
				if (tab[i][j][k] == 1)
				{
					if (k != 0)
						write(1, " ", 1);
					c = k + 1 + '0';
					write(1, &c, 1);
					c = j + '0';
					write(1, " [", 2);
					write(1, &c, 1);
					write(1, "] ", 2);
				}		
				k++;
			}
			j++;
		}
		if (i != ord - 1)
			write(1, "\n", 1);
		i++;
	}
}
