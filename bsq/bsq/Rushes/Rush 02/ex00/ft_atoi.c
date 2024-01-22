/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperez-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 13:22:58 by aperez-b          #+#    #+#             */
/*   Updated: 2021/03/14 09:33:50 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspce(char *str);

unsigned int		ft_atoi(char *str)
{
	unsigned long		nbr;
	char	sign;
	int length;

	length = 0;
	nbr = 0;
	sign = '+';
	while (ft_isspce(str) == 1)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = '-';
		str++;
	}
		
	while (*str != ':')
	{
		if (*str >= 48 && *str <= 57)
			nbr = (nbr * 10) + *str - '0';
		else
			return (-1);
		str++;
		length++;
	}
	if (nbr <= 4294967295)
	{
		if (sign == '-')
			return (-1);
		return (nbr);
	}
	return (-1);
	
}

int		ft_isspce(char *str)
{
	if ((*str >= 9 && *str <= 13) || *str == ' ')
		return (1);
	return (0);
}