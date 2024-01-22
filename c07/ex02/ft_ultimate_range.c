/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:12:40 by lofiorin          #+#    #+#             */
/*   Updated: 2023/09/28 17:12:42 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	get_size(int min, int max)
{
	return (max - min);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	tot_size;
	int	*res;

	*range = NULL;
	if (min >= max)
		return (0);
	tot_size = get_size (min, max);
	res = malloc(sizeof(int *) * tot_size);
	if (!res)
		return (-1);
	i = -1;
	while (++i < tot_size)
		res[i] = min + i;
	*range = res;
	return (tot_size);
}
