/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unica_poss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 23:32:46 by anomourn          #+#    #+#             */
/*   Updated: 2023/09/17 23:33:01 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	unica_poss(int *tab, int ord)
{
	int	i;
	int	poss;
	int	cont;

	cont = 0;
	poss = 1;
	while (poss <= ord && cont != 1)
	{
		i = 0;
		cont = 0;
		while (i < ord)
		{
			if(tab[poss - 1] == 1)
				cont++;
			i++;
		}
		poss++;
	}
	if (cont == 1)
		return (poss);
	else
		return (0);
}

