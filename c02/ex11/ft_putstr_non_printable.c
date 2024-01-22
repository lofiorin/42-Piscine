/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:10:31 by lofiorin          #+#    #+#             */
/*   Updated: 2023/09/13 11:10:36 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_hex_putchar(char c)
{
	char	sub[3];
	int		i;

	i = 0;
	sub[0] = '\\';
	sub[2] = c % 16;
	sub[1] = (c - sub[2]) / 16;
	sub[1] += 48;
	if (sub[2] > 9)
		sub[2] += 87;
	else
		sub[2] += 48;
	while (sub[i] != '\0')
	{
		write(1, &sub[i], 1);
		i++;
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
			ft_hex_putchar(str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}
