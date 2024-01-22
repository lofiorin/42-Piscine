/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 11:21:52 by aperez-b          #+#    #+#             */
/*   Updated: 2021/03/18 08:05:06 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str, int limit)
{
	unsigned long	nbr;
	int				i;

	i = 0;
	nbr = 0;
	if (str[i] < '0' || str[i] > '9')
		return (-1);
	while (str[i] >= '0' && str[i] <= '9' && i != limit)
	{
		nbr = (nbr * 10) + str[i] - '0';
		i++;
	}
	if (nbr <= 4294967295)
		return (nbr);
	return (-1);
}
