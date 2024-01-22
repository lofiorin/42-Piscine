/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 11:47:24 by odudniak          #+#    #+#             */
/*   Updated: 2023/09/24 19:13:06 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

void	order_dict_list(t_dielement *list, int size)
{
	int			i;
	int			j;
	t_dielement	tmp;

	i = -1;
	while (++i < size)
	{
		j = i - 1;
		while (++j < size)
		{
			if (list[i].key < list[j].key)
			{
				tmp = list[i];
				list[i] = list[j];
				list[j] = tmp;
			}
		}
	}
}

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long	ft_atoi(const char *str)
{
	unsigned long	res;
	int				i;

	i = 0;
	if (!str[i] || (str[i] == '+' || str[i] == '-'))
		return (-1);
	res = 0;
	while (str[i] && ft_is_digit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	while (str[i] != ':' && str[i])
	{
		if (str[i] != ' ')
			return (-1);
		i++;
	}
	if (!ft_is_digit(str[0]))
		return (-1);
	return (res);
}

int	check_args(int ac, char **av)
{
	char		*number;

	if (ac == 1 || ac > 3 || (ac == 2 && ft_strlen(av[1]) == 0)
		|| (ac == 3 && ft_strlen(av[2]) == 0))
		return (-1);
	number = av[1];
	if (ac == 3)
		number = av[2];
	if (*number == '+')
		number++;
	if (ft_strlen(number) > 19)
		return (-1);
	while (*number)
	{
		if (*number < '0' || *number > '9')
			return (-1);
		number++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_dielement	*dict;
	int			dict_size;

	if (check_args(ac, av) != 0)
		return (ft_errormsg(""));
	if (ac == 2)
		dict = parse_dict_file("numbers.dict", &dict_size);
	else
		dict = parse_dict_file(av[1], &dict_size);
	if (dict == NULL)
		return (ft_errormsg("Dict "));
	if (ac == 2)
		ft_print(ft_atoi(av[1]), dict, 1);
	else
		ft_print(ft_atoi(av[2]), dict, 1);
	free(dict);
	return (0);
}
