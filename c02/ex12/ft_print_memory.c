/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:34:03 by lofiorin          #+#    #+#             */
/*   Updated: 2023/09/13 17:34:08 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	*c;
	char	arr[8];
	int		i;

	i = 0;
	*c = (char *) addr;
	while (i < 7)
	{
		arr[i] = *c / 16;
		*c = *c / 16;
		i++;
	}
	arr[i] = *c % 16;
	i = 0;
	while (i < 8)
	{
		write(1, &arr[i], 1);
		i++;
	}
	return (addr);
}
