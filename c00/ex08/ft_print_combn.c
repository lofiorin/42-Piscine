/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 23:26:52 by lofiorin          #+#    #+#             */
/*   Updated: 2023/09/07 23:26:59 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int n, char *array, int flag)
{
	int	i;

	if (flag == 1)
	{
		write(1, ", ", 2);
	}
	i = 0;
	while (i < n)
	{
		write(1, &array[i], 1);
		i++;
	}
}

void	ft_increment(int n, char array[])
{
	int		i;
	char	num_max;

	num_max = '9';
	i = n - 1;
	while (array[i] == num_max)
	{
		i--;
		num_max--;
	}
	array[i]++;
	while (i < n - 1)
	{
		array[i + 1] = array[i] + 1;
		i++;
	}
}

void	ft_print_combn(int n)
{
	char	array[10];
	int		i;

	i = 0;
	while (i < n)
	{
		array[i] = i + 48;
		i++;
	}
	print(n, array, 0);
	while ((array[0] != '9' - n + 1) || array[n - 1] != '9')
	{
		if (array[n - 1] != '9')
			array[n - 1]++;
		else
			ft_increment(n, array);
		print(n, array, 1);
	}
}
