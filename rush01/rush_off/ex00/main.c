/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 23:35:05 by anomourn          #+#    #+#             */
/*   Updated: 2023/09/17 23:35:36 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	ord;
	int	cont;
	int	**arr;

	ord = set_ord(argv[1]);
	if (ord <= 0 || argc != 2 || argv[1][0] == ' ')
	{
		write(1, "Error\n", 6);
		return (0);
	}
	i = 0;
	arr = (int **) malloc(4 * 8 * 4);
	while (i < ord)
		arr[i++] = (int *) malloc(ord * 4);
	cont = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < ord)
		{
			arr[i][j] = argv[1][cont] - '0';
			cont += 2;
			j++;
		}
		i++;
	}
	crea_tabella(arr, ord);
	i = 0;
	while (i < ord)
		free(arr[i++]);
	free(arr);
	return (0);
}
