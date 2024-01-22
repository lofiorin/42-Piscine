/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lofiorin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:13:57 by lofiorin          #+#    #+#             */
/*   Updated: 2023/09/28 17:13:59 by lofiorin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_len;

	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i])
	{
		dest[i + dest_len] = src[i];
		i++;
	}
	dest[i + dest_len] = '\0';
	return (dest);
}

int	get_tot_size(int size, char **strs, char *sep)
{
	int	i;
	int	sep_len;
	int	tot_size;

	sep_len = ft_strlen(sep);
	tot_size = sep_len * size;
	i = -1;
	while (++i < size)
		tot_size += ft_strlen(strs[i]);
	return (tot_size);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		tot_size;
	char	*res;

	res = NULL;
	if (size <= 0)
	{
		res = malloc(sizeof(char) * 1);
		res[0] = '\0';
		return (res);
	}
	tot_size = get_tot_size(size, strs, sep);
	res = malloc(sizeof(char) * tot_size);
	res[0] = '\0';
	i = -1;
	while (++i < size)
	{
		ft_strcat(res, strs[i]);
		if (i < size - 1)
			ft_strcat(res, sep);
	}
	return (res);
}
