/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:50:34 by odudniak          #+#    #+#             */
/*   Updated: 2023/09/24 19:50:35 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "header.h"

t_dielement	create_dival(int n, char *value)
{
	t_dielement	res;

	res.key = n;
	res.value = value;
	return (res);
}

int	parse_dict_lines(t_file_lines lines, t_dielement *dict)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	while (i < lines.size)
	{
		j = 0;
		while (lines.lines[i][j] != ':' && lines.lines[i][j])
			j++;
		if (j == ft_strlen(lines.lines[i]))
			return (0);
		j++;
		while (lines.lines[i][j] == ' ')
			j++;
		num = ft_atoi(ft_split(lines.lines[i], ':')[0]);
		if (num == -1)
			return (0);
		dict[i] = create_dival(num, &lines.lines[i][j]);
		i++;
	}
	return (1);
}

t_dielement	*parse_dict_file(char *filename, int *dict_size)
{
	t_dielement		*dict;
	int				fd;
	t_file_lines	all_lines;
	char			buffer[51200];
	int				i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	while (read(fd, buffer, 51200) > 0)
	{
	}
	all_lines.lines = ft_split(buffer, '\n');
	all_lines.size = ft_count_char(buffer, '\n');
	*dict_size = all_lines.size;
	dict = malloc(sizeof (t_dielement) * all_lines.size);
	if (parse_dict_lines(all_lines, dict) == 0)
		return (NULL);
	close(fd);
	return (dict);
}
