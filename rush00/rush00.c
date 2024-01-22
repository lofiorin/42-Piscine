/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 10:55:54 by tfalchi           #+#    #+#             */
/*   Updated: 2023/09/09 10:55:57 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char valore);

void	ins_char(int i, int j, int x, int y)
{
	if (i == 0 || i == y - 1 || j == 0 || j == x - 1)
	{
		if ((j == 0 && i == 0) || (j == x - 1 && i == y - 1)) 
			ft_putchar('/');
		else if ((j == x - 1 && i == 0) || (j == 0 && i == y - 1))
			ft_putchar('\\');
		else
			ft_putchar('*');
	}
	else
	{
		ft_putchar(' ');
	}
}

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < y)
	{
		while (j < x)
		{
			ins_char(i, j, x, y);
			j++;
		}
		ft_putchar('\n');
		j = 0;
		i++;
	}
}
