/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:55:09 by odudniak          #+#    #+#             */
/*   Updated: 2023/09/24 11:13:58 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_errormsg(char *prefix)
{
	if (ft_strlen(prefix) > 0)
		ft_putstr(prefix);
	ft_putstr("Error\n");
	return (1);
}

int	ft_count_char(char *str, char c)
{
	int	counter;
	int	i;

	counter = 0;
	i = -1;
	while (str[++i])
		if (str[i] == c)
			counter++;
	return (counter);
}

char	*ft_create_substr(char *s, int start, int end)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(sizeof(char) * ((end - start) + 1));
	i = start;
	j = 0;
	while (i <= end)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	**ft_split(char *s, char c)
{
	char	**new;
	int		size;
	int		i;
	int		idx;
	int		start;

	i = -1;
	size = 0;
	while (s[++i])
		if (s[i] == c)
			size++;
	new = malloc(sizeof(char *) * (size));
	i = -1;
	start = 0;
	idx = 0;
	while (s[++i])
	{
		if (s[i] == c)
		{
			new[idx] = ft_create_substr(s, start, i - 1);
			start = i + 1;
			idx++;
		}
	}
	return (new);
}
