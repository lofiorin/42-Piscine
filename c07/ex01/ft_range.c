/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:09:40 by lofiorin          #+#    #+#             */
/*   Updated: 2023/09/28 17:09:44 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	get_size(int min, int max)
{
	return (max - min);
}

int	*ft_range(int min, int max)
{
	int	i;
	int	tot_size;
	int	*res;

	res = NULL;
	if (min >= max)
		return (res);
	tot_size = get_size (min, max);
	res = malloc(sizeof(int *) * tot_size);
	i = -1;
	while (++i < tot_size)
		res[i] = min + i;
	return (res);
}
